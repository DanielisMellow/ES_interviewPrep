import os
import shutil

sourcePath = "/home/lizardking/Downloads"
destPath = "/home/lizardking/Videos/"

# destPath = "/home/lizardking/Videos/Movies/"
# sourcePath = "/home/lizardking/Videos/"


def move_videos(src: str, dest: str):
    # Video extensions
    vide_extensions = [".mp4", ".avi", ".mkv", ".flv", ".mov", ".wmv"]

    # os.walk
    for subdir, dir, files in os.walk(src):
        for file in files:
            if any(file.endswith(ext) for ext in vide_extensions):
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


def main():
    source_dir = sourcePath
    target_dir = destPath

    if not os.path.exists(target_dir):
        print(f"Creating Target Dir: {target_dir}")
        os.makedirs(target_dir)

    move_videos(source_dir, target_dir)
    print("Done!")


if __name__ == "__main__":
    main()
