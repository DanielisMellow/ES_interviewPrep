import pickle


def save_dict(dict_to_save, file_path):
    with open(file_path, "wb") as file:
        pickle.dump(dict_to_save, file)


def load_dict(file_path):
    with open(file_path, "rb") as file:
        return pickle.load(file)


def main():
    build = {"type": "human", "name": "Daniel", "age": 24, "views": "existentialist"}

    save_dict(build, r"challenges/build.pickle")

    recover = load_dict(r"challenges/build.pickle")
    print(recover)


if __name__ == "__main__":
    main()
