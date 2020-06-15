def stringTree(n):
    if (n <= 0):
        return [];
    espaco = n - 1
    arvore = []
    for i in range(n):
        linha = ""
        if (espaco > 0):
            for j in range(espaco):
                linha += " "
        for j in range(n-espaco):
            linha += "#"
        espaco -= 1
        arvore.append(linha)
    return arvore

def main():
    n = int(input("Altura da árvore: "))
    esc = stringTree(n)
    for i in range(n):
        print(esc[i])

main()


