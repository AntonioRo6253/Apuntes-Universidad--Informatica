def ascii_mayus(char_local):
    if 'a' <= char_local <= 'z':
        return chr(ord(char_local) - 32)  # Convertir a mayuscula
    else:
        return chr(ord(char_local) + 32)  # Convertir a minuscula

def main():
    while True:
        analizar_caracter = input("Introduce tu letra: ")
        if len(analizar_caracter) != 1:
            print("Por favor, introduce solo un carácter.")
            continue

        analizar_caracter_ascii = ord(analizar_caracter)
        print(f'Tu caracter es el siguiente: "{analizar_caracter}"')
        print(f"ASCII: {analizar_caracter_ascii}")
        print(f"Invertido: {ascii_mayus(analizar_caracter)}")

        respuesta = input("¿Quieres volver a ejecutar? (s/n): ")
        if respuesta.lower() != 's':
            break

if __name__ == "__main__":
    main()