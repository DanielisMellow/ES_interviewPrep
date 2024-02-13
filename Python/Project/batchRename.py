import os
import shutil

from MovieOrganizer import move_videos

SOURCE_PATH = "/home/lizardking/Downloads"
DEST_PATH = "/home/lizardking/Videos/"

VIDEO_PATH = "/home/lizardking/Videos/"

tStrings = [
    ".2160p",
    ".1080p",
    "1080p",
    ".4K",
    ".BluRay",
    ".1-[YTS.MX]",
    ".x256-[YTS.AM]",
    ".x264-[YTS.AM]",
    ".x256",
    ".x265",
    ".10bit",
    ".AAC5",
    ".UNCUT",
    ".WEB",
    ".YIFY",
    ".DC",
    ".REPACK",
    ".HDR",
    ".BrRip",
]


def removeLastDelimiter(file_name: str) -> str:
    # Find the last occurrence of the delimiter
    last_period_idx = file_name.rfind(".")

    if last_period_idx != -1:
        # Remove Everything after the last period using slicing
        result = file_name[:last_period_idx]

    else:
        # If there's no period, keep the original filename
        result = file_name
    return result


def file_movies(dirPathToOrginze: str, folderName: str):
    """Moves movies to movie folder"""
    # Video extensions
    video_extensions = [".mp4", ".avi", ".mkv", ".flv", ".mov", ".wmv"]

    movie_dir = os.path.join(dirPathToOrginze, folderName)
    if not os.path.exists(movie_dir):
        os.makedirs(movie_dir)

    # Return a list of filenames in Dir
    files = os.listdir(dirPathToOrginze)

    for filename in files:
        sourcePath = os.path.join(dirPathToOrginze, filename)
        if any(filename.endswith(ext) for ext in video_extensions):

            destination = os.path.join(movie_dir, filename)
            # Ensure The destination path doesn't overwrite an exisiting file
            counter = 1
            while os.path.exists(destination):
                name, ext = os.path.splitext(filename)
                destination = os.path.join(movie_dir, f"{name}_{counter}{ext}")
                counter += 1
            print(f"Moving {sourcePath} to {destination}")
            shutil.move(sourcePath, destination)


def renameFiles(srcPath: str, targetStringList: list, reString: str):
    # Returns a list of filenames in a Dir
    files = os.listdir(srcPath)

    try:
        # Iterate through all the files in the folder
        for fileName in files:
            if os.path.isfile(fileName):
                # Split the file name into name and extension
                name_part, ext = os.path.splitext(fileName)

                for targetString in targetStringList:
                    # If The target string is found in the file names,
                    # replace it with an empty string
                    if targetString in name_part:
                        name_part = name_part.replace(targetString, reString)

                # Remove everything after last delimiter usually a year
                # newFileName = removeLastDelimiter(name_part)
                # Create new File name
                newFileName = name_part + ext

                # Construct the full paths for old and new filenames
                original_path = os.path.join(srcPath, fileName)
                updated_path = os.path.join(srcPath, newFileName)

                # rename the files
                os.rename(original_path, updated_path)

                print(f"{fileName} -----------> {newFileName}")

    except FileNotFoundError:
        print(f"Folder '{srcPath}' not found.")
    except Exception as e:
        print(f"AN error occurred: {str(e)}")


def main():

    source_dir = SOURCE_PATH
    target_dir = DEST_PATH

    if not os.path.exists(target_dir):
        print(f"Creating Target Dir: {target_dir}")
        os.makedirs(target_dir)

    move_videos(source_dir, target_dir)
    print("\n=================================================================\n")

    renameFiles(VIDEO_PATH, tStrings, "")
    renameFiles(VIDEO_PATH, ".", "_")
    file_movies(VIDEO_PATH, r"Movies")


if __name__ == "__main__":
    main()
