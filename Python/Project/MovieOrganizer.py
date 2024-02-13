import os
import shutil


def move_videos(src: str, dest: str):
    """Moves files from src to dest path"""
    # Video extensions
    video_extensions = [".mp4", ".avi", ".mkv", ".flv", ".mov", ".wmv"]

    # os.walk
    for subdir, dir, files in os.walk(src):
        for file in files:
            if any(file.endswith(ext) for ext in video_extensions):
                source_path = os.path.join(subdir, file)
                destination_path = os.path.join(dest, file)

                # Ensure The Destination path doesn't overwrite an existing file

                counter = 1
                while os.path.exists(destination_path):
                    name, ext = os.path.splitext(file)
                    destination_path = os.path.join(dest, f"{name}_{counter}{ext}")
                    counter += 1

                print(f"Moving {source_path} to {destination_path}")
                shutil.move(source_path, destination_path)
