import cv2
import os
from tqdm import tqdm
from mtcnn import MTCNN

def convert_to_yolo_format(image_shape, box):
    image_width, image_height = image_shape[1], image_shape[0]

    x_min, y_min, width, height = box
    x_center = (x_min + width / 2) / image_width
    y_center = (y_min + height / 2) / image_height
    width /= image_width
    height /= image_height
    
    return x_center, y_center, width, height

def detect_faces(image, output_dir, frame_name):
    image_rgb = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    detector = MTCNN()
    faces = detector.detect_faces(image_rgb)
    image_shape = image.shape
    
    txt_file_path = os.path.join(output_dir, os.path.splitext(frame_name)[0] + ".txt")
    with open(txt_file_path, "w") as txt_file:
        for i, face in enumerate(faces):
            x_center, y_center, width, height = convert_to_yolo_format(image_shape, face['box'])
            txt_file.write(f"29 {x_center:.6f} {y_center:.6f} {width:.6f} {height:.6f}\n")

def FrameCapture(video_path, output_dir, frame_period):
    vidObj = cv2.VideoCapture(video_path)
    total_frames = int(vidObj.get(cv2.CAP_PROP_FRAME_COUNT))
    count = 0
    max_frames = min(total_frames // frame_period, 2000)
    pbar = tqdm(total=max_frames, desc="Extracting frames from %s" % os.path.basename(video_path), unit="frame")
    video_name = os.path.splitext(os.path.basename(video_path))[0]
    success = 1
    while success and count // frame_period < max_frames:
        success, image = vidObj.read()
        if success:
            if count % frame_period == 0:
                os.makedirs(output_dir, exist_ok=True)
                frame_name = "%s_f%03d.jpg" % (video_name, count // frame_period + 1)
                frame_path = os.path.join(output_dir, frame_name)
                cv2.imwrite(frame_path, image)
                detect_faces(image, output_dir, frame_name)
                pbar.update(1)
        count += 1
    pbar.close()

# INPUT_____________________________
videos_folder = "/home/hi-born4/6th Sem/Image Processing and Computer Vision/Annotated Videos"
frame_period = 5______________________________

for root, dirs, files in os.walk(videos_folder):
    for video_file in files:
        if video_file.endswith(".mp4"):
            video_path = os.path.join(root, video_file)
            video_base_name = os.path.splitext(video_file)[0]
            video_subdir = os.path.join(root, video_base_name)
            FrameCapture(video_path, video_subdir, frame_period)