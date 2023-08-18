from collections import Counter


def get_common_products(products_purchased):
    counter = Counter(products_purchased)
    common_prods = counter.most_common(3)
    return common_prods


def main():
    products_purchased = [
        "DES005",
        "BEV003",
        "DES004",
        "DES001",
        "DES002",
        "DES003",
        "DES002",
        "DES002",
        "STA004",
        "SAL004",
        "ENT005",
        "BEV003",
        "SAL002",
        "ENT005",
        "SAL004",
        "ENT004",
        "ENT004",
        "DES004",
        "BEV001",
        "STA001",
        "STA003",
        "BEV002",
        "STA003",
        "DES005",
        "BEV002",
        "ENT004",
        "ENT001",
        "DES005",
        "ENT004",
        "STA005",
        "ENT005",
        "DES002",
        "ENT001",
        "SAL001",
        "BEV001",
        "DES002",
        "BEV001",
        "DES004",
        "ENT004",
        "DES001",
        "STA005",
        "DES004",
        "ENT002",
        "DES001",
        "ENT002",
        "ENT003",
        "BEV001",
        "DES004",
        "STA005",
        "STA003",
        "SAL002",
        "ENT001",
        "SAL004",
        "STA005",
        "ENT002",
        "DES004",
        "DES004",
        "SAL001",
        "BEV003",
        "DES001",
    ]
    print(get_common_products(products_purchased))


if __name__ == "__main__":
    main()
