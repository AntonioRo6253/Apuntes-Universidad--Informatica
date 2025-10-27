#-----------------------------------------------Declarando las variables----------------------------------------------------------------
boolTrue = True
boolFalse = False
combinacionesTablasDeVerdad = [[True,True],[False,False],[True,False],[False,True]]

#-----------------------------------------------Mostrar las tablas de verdad------------------------------------------------------------
print("Mostrando True :", boolTrue)
print("Mostrando False :", boolFalse)

print("\n\nMostrando Operador AND")

for i in range(4):
    print(f"{combinacionesTablasDeVerdad[i][0]} and {combinacionesTablasDeVerdad[i][1]} = {combinacionesTablasDeVerdad[i][0] and combinacionesTablasDeVerdad[i][1]}")


print("Mostrando Operador OR")

for i in range(4):
    print(f"{combinacionesTablasDeVerdad[i][0]} or {combinacionesTablasDeVerdad[i][1]} = {combinacionesTablasDeVerdad[i][0] or combinacionesTablasDeVerdad[i][1]}")


print("\n\nMostrando la negacion simple")
print(f"El valor original es {boolTrue} y su negacion es {not boolTrue}")
print(f"Mostrando la negacion simple")
print(f"El valor original es {boolFalse} y su negacion es {not boolFalse}")


print("\n\nMostrando Operador AND/NAND con negacion")

for i in range(4):
    print(f"{combinacionesTablasDeVerdad[i][0]} and {combinacionesTablasDeVerdad[i][1]} = {not (combinacionesTablasDeVerdad[i][0] and combinacionesTablasDeVerdad[i][1])}")


print("Mostrando Operador OR/NOR con negacion")

for i in range(4):
    print(f"{combinacionesTablasDeVerdad[i][0]} or {combinacionesTablasDeVerdad[i][1]} = {not (combinacionesTablasDeVerdad[i][0] or combinacionesTablasDeVerdad[i][1])}")