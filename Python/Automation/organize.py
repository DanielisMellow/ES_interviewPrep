import os
from pathlib import Path

SUB_DIRS = {
    "DOCUMENTS": [".pdf", ".rtf", ".txt"],
    "AUDIO": [".m4a", ".m4b", ".mp3"],
    "VIDEOS": [".mov", ".avi", ".mp4"],
    "IMAGES": [".jpg", ".jpeg", ".png"],
}


def pickDir(value):
    for category, sufixes in SUB_DIRS.items():
        for suffix in sufixes:
            if suffix == value:
                return category
    return "MISC"


def organizeDir():
    for item in os.scandir():
        if item.is_dir():
            continue
        filePath = Path(item)
        fileType = filePath.suffix.lower()
        directory = pickDir(fileType)
        directoryPath = Path(directory)
        if directoryPath.is_dir() != True:
            directoryPath.mkdir()
        # This allow us to move our file into the directory by changing the file path to join with the directory's path
        filePath.rename(directoryPath.joinpath(filePath))


organizeDir()
