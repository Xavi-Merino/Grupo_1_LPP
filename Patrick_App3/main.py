import numpy as np

def encontrar_entrada(matriz, i):
    return (i if matriz[i][0] == 0 else encontrar_entrada(matriz,i+1))
    
def entrada_laberinto(laberinto):
    return [encontrar_entrada(laberinto, 0), 0]

def encontrar_salida(matriz, i):
    return (i if matriz[i][matriz.shape[1]-1] == 0 else encontrar_salida(matriz,i+1))

def salida_laberinto(laberinto):
    return [encontrar_salida(laberinto, 0), laberinto.shape[1]-1]

def arriba(recorrido, laberinto, posicion):
    if posicion[0]-1 >= 0: 
        if (laberinto[posicion[0]-1][posicion[1]] != 1):
            if not ya_recorri(recorrido, [posicion[0]-1,posicion[1]], 0):
                return True
    return False

def izquierda(recorrido, laberinto, posicion):
    if posicion[1]-1 >= 0: 
        if (laberinto[posicion[0]][posicion[1]-1] != 1):
            if not ya_recorri(recorrido, [posicion[0],posicion[1]-1], 0):
                return True
    return False

def derecha(recorrido, laberinto, posicion):
    if posicion[1]+1 < laberinto.shape[0]: 
        if (laberinto[posicion[0]][posicion[1]+1] != 1):
            if not ya_recorri(recorrido, [posicion[0],posicion[1]+1], 0):
                return True
    return False

def abajo(recorrido, laberinto, posicion):
    if posicion[0]+1 < laberinto.shape[1]: 
        if (laberinto[posicion[0]+1][posicion[1]] != 1):
            if not ya_recorri(recorrido, [posicion[0]+1,posicion[1]], 0):
                return True
    return False

def ya_recorri(recorrido, posicion, i):
    if i >= len(recorrido):
        return False
    return (True if recorrido[i] == posicion else ya_recorri(recorrido, posicion, i+1))

def revisar_4_sentidos(recorrido, laberinto, posicion, salida):
    return (
        buscando_caminos(recorrido, laberinto, [posicion[0], posicion[1]+1], salida) #avanza derecha
        if (derecha(recorrido, laberinto, posicion))
        else []
    ) + (
        buscando_caminos(recorrido, laberinto, [posicion[0], posicion[1]-1], salida) #avanza izquierda
        if (izquierda(recorrido, laberinto, posicion))
        else []
    ) + (
        buscando_caminos(recorrido, laberinto, [posicion[0]-1, posicion[1]], salida) #avanza arriba
        if (arriba(recorrido, laberinto, posicion))
        else []
    ) + (
        buscando_caminos(recorrido, laberinto, [posicion[0]+1, posicion[1]], salida) #avanza abajo
        if (abajo(recorrido, laberinto, posicion))
        else []
    )

def buscando_caminos(recorrido, laberinto, posicion, salida):
    if posicion == salida:
        return [recorrido+[posicion]]
    return revisar_4_sentidos(recorrido+[posicion], laberinto, posicion, salida)

def iniciar(laberinto):
    return str(buscando_caminos(
            [],
            laberinto,
            entrada_laberinto(laberinto), 
            salida_laberinto(laberinto)
    ))

def laberinto():
    return np.loadtxt("input.txt").astype('int32')

def main(): 
    return open('output.txt', 'w').write(iniciar(laberinto()))

if __name__ == '__main__':
    main()
