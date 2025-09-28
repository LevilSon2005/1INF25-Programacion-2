
''' Crea un programa que te de un saluda de acuerdo a la hora '''

hora = int(input("Ingrese la hora en formato de 24h, es decir, solo la hora"))
nombre = input("Ingrese su nombre completo")
if( hora >= 0 and hora < 24):
    if(hora <=5):
        print(f"Hola {nombre}es de madrugada")
    elif (hora <= 12):
        print(f"Buenos dias, {nombre}")
    elif(hora <= 19):
        print(f"Buenas tardes, {nombre}")
    else:
        print(f"Buenas noches, {nombre}")
else:
    print("FORMATO INCORRECTO")