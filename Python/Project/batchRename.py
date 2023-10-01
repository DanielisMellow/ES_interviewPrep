import os

sPath = "/home/lizardking/Videos/Movies/Movies"

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


def renameFiles(srcPath: str, targetStringList: list, reString: str):
    # Returns a list of filenames in a Dir
    files = os.listdir(srcPath)

    try:
        # Iterate through all the files in the folder
        for fileName in files:
            # Split the file name into name and extension
            name_part, ext = os.path.splitext(fileName)

            for targetString in targetStringList:
                # If The target string is found in the file names,
                # replace it with an empty string
                if targetString in name_part:
                    name_part = name_part.replace(targetString, reString)

            # Remove everything after last delimiter usually a year
            newFileName = removeLastDelimiter(name_part)
            # Create new File name
            newFileName = newFileName + ext

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
    renameFiles(sPath, tStrings, "")
    renameFiles(sPath, ".", "_")


if __name__ == "__main__":
    main()
