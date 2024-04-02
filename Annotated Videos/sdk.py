import labelbox
LB_API_KEY = ''
client = labelbox.Client(api_key = LB_API_KEY)
export_task = labelbox.ExportTask.get_task(client, "clsz172d1077o07za8i9ndsu3")

# Download the file to a local path
export_task.get_stream(converter=labelbox.FileConverter(file_path=output_file_path)).start()


def json_stream_handler(output: labelbox.JsonConverter.Output):
  print(output.json_str)

# Stream the file to stdout
export_task.get_stream().start(stream_handler=json_stream_handler)