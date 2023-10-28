import cv2
import numpy as np
import imutils

rojoBajo1 = np.array([0, 140, 90], np.uint8)
rojoAlto1 = np.array([8, 255, 255], np.uint8)
rojoBajo2 = np.array([160, 140, 90], np.uint8)
rojoAlto2 = np.array([180, 255, 255], np.uint8)



# leer imagen

image = cv2.imread('C:\\Users\\elvan\\Downloads\\uabc_3_sem\\lenguaje c\\lenguajeC\\actividad_escalaColores\\flor.jpg')
image = imutils.resize(image, width=640)

# transformando a otros espacios de color
imageGray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
imageHSV = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

# detectando el color rojo
maskRojo1 = cv2.inRange(imageHSV, rojoBajo1, rojoAlto1)
maskRojo2 = cv2.inRange(imageHSV, rojoBajo2, rojoAlto2)
mask = cv2.add(maskRojo1, maskRojo2)


cv2.imshow('image', image)
cv2.imshow('mask', mask)
cv2.waitKey(0)
cv2.destroyAllWindows()