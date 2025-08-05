# Variables
numeroSimple = 10
numeroDecimal = 5.5
unCaracterMinus = 'l'
unCaracterMayus = 'L'
unTexto = "Hola mundo"
decimalCorto = 32767
decimalCortoFueraDeLimite = 32768

# Impresiones Normales
print(f"numeroSimple: {numeroSimple}")
print(f"numeroDecimal: {numeroDecimal}")
print(f"CaracterMinus: {unCaracterMinus}")
print(f"CaracterMayus: {unCaracterMayus}")
print(f"Texto: {unTexto}")
print(f"decimalCorto: {decimalCorto}")
print(f"decimalCortoFueraDeLimite: {decimalCortoFueraDeLimite}")

# pruebas
numeroDecimalFueraDeLimite = 2147483648.0  
print(f"numeroDecimal fuera de limite: {numeroDecimalFueraDeLimite}")
print(f"numeroSimple mas 3: {numeroSimple + 3}")
print(f"numeroSimple menos 3: {numeroSimple - 3}")
print(f"numeroSimple por 3: {numeroSimple * 3}")
print(f"numeroSimple entre 3: {numeroSimple // 3}")
print(f"numeroSimple residuo de entre 3: {numeroSimple % 3}")
print(f"numeroSimple exponente 2: {numeroSimple * numeroSimple}")