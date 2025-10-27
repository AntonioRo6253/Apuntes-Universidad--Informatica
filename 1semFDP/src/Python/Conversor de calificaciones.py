def calcular_calificacion():
    while True:
        try:
            eleccion_p1 = int(input("¿Quieres escribir tu calificación o elegir una opción rápida?\n1. Manual 2. Rápida: "))
        except ValueError:
            print("Opción no válida.")
            continue

        if eleccion_p1 == 1:
            try:
                calificacion = float(input("Dame tu calificación: "))
            except ValueError:
                print("Entrada no válida. Debes ingresar un número.")
                continue

            if calificacion < 0 or calificacion > 100:
                print(f"Error, tu número: {calificacion}, no es una calificación válida.")
            elif 97 <= calificacion <= 100:
                print(f"Tu calificación es: {calificacion}, así que tienes una A+")
            elif 93 <= calificacion <= 96:
                print(f"Tu calificación es: {calificacion}, así que tienes una A")
            elif 90 <= calificacion <= 92:
                print(f"Tu calificación es: {calificacion}, así que tienes una A-")
            elif 87 <= calificacion <= 89:
                print(f"Tu calificación es: {calificacion}, así que tienes una B+")
            elif 83 <= calificacion <= 86:
                print(f"Tu calificación es: {calificacion}, así que tienes una B")
            elif 80 <= calificacion <= 82:
                print(f"Tu calificación es: {calificacion}, así que tienes una B-")
            elif 77 <= calificacion <= 79:
                print(f"Tu calificación es: {calificacion}, así que tienes una C+")
            elif 73 <= calificacion <= 76:
                print(f"Tu calificación es: {calificacion}, así que tienes una C")
            elif 70 <= calificacion <= 72:
                print(f"Tu calificación es: {calificacion}, así que tienes una C-")
            elif 60 <= calificacion <= 69:
                print(f"Tu calificación es: {calificacion}, así que tienes una D")
            else:
                print(f"Tu calificación es: {calificacion}, así que tienes una F")

        elif eleccion_p1 == 2:
            array_calificaciones = [
                ["A+", "97-100"],
                ["A", "93-96"],
                ["A-", "90-92"],
                ["B+", "87-89"],
                ["B", "83-86"],
                ["B-", "80-82"],
                ["C+", "77-79"],
                ["C", "73-76"],
                ["C-", "70-72"],
                ["D+", "67-69"],
                ["D", "65-66"],
                ["F", "Menos de 65"]
            ]
            print("Estas son las opciones:")
            for i in range(12):
                print(f"{i + 1}.({array_calificaciones[i][1]})")

            try:
                respuesta_rapida = int(input("Elige una opción: "))
            except ValueError:
                print("Opción no válida.")
                continue

            if 1 <= respuesta_rapida <= 12:
                print(f"Tu calificación es una: {array_calificaciones[respuesta_rapida - 1][0]}")
            else:
                print("Opción no válida.")

        else:
            print("Opción no válida.")

        respuesta = input("¿Quieres calcular otra calificación? (s/n): ").lower()
        if respuesta != 's':
            break

calcular_calificacion()