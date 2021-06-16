import numpy as np

def encontrar_entrada(matriz, i):
    return (i if matriz[i][0] == 0 else encontrar_entrada(matriz,i+1))
    

def encontrar_salida(matriz, i):
    return (i if matriz[i][matriz.shape[1]-1] == 0 else encontrar_salida(matriz,i+1))

def buscando_caminos(recorrido, laberinto, posicion, salida):
    #explora las cuatro direcciones
    if laberinto[posicion[0]][posicion[1]] == 1:
        return #Comprueba altiro si donde estoy es pared, entonces corta la rama

    if posicion == salida:
        return [salida]

    if comprobar_si_ya_recorri(recorrido, posicion, 0):
        return

    #return recorrido+[buscando_caminos(recorrido+[posicion], laberinto, [posicion[0]+1, posicion[1]], salida)] #avanza derecha
    buscando_caminos(recorrido+[posicion], laberinto, [posicion[0]-1, posicion[1]], salida) #avanza izquierda
    buscando_caminos(recorrido+[posicion], laberinto, [posicion[0], posicion[1]+1], salida) #avanza arriba
    buscando_caminos(recorrido+[posicion], laberinto, [posicion[0], posicion[1]-1], salida) #avanza abajo
    
    return


def comprobar_si_ya_recorri(recorrido, posicion, i):
    if i >= len(recorrido):
        return False
    return (True if recorrido[i] == posicion else comprobar_si_ya_recorri(recorrido, posicion, i+1))

if __name__ == '__main__':

    laberinto = np.loadtxt("input.txt").astype('int32')
    print(laberinto)    

    entrada = [encontrar_entrada(laberinto, 0), 0] #Eliminar variable luego
    salida = [encontrar_salida(laberinto, 0), laberinto.shape[1]-1] #Eliminar variable luego
    print("Entrada:", entrada, "\nSalida:", salida)
    

    #buscando_caminos([entrada], laberinto, entrada, salida)



    
