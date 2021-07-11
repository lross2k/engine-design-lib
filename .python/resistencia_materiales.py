""""
Created on wednesday june  30 12:33:13 2021
Implementación de sección resistencia de materiales, de  condición de espesor del tubo hasta areas afectadas por tornillos
"""

from numpy import arcsin,cos,tan,pi,e
"""Variables necesarias de partes anteriores
temp_E13= 0.0730
temp_E13= float(temp_E13)
temp_E14= 0.0052
temp_E15= 0.0314"""
# Resistencia de materiales / condición de espesor del  tuvo 
Diametro_Medio_de_tubo = 0 
Diametro_Medio_de_tubo = float(temp_E13-temp_E14) # Dm = Dext-Esp
print("diametro medio del tubo", Diametro_Medio_de_tubo)
Condicion_Espesor= 0
Condicion_Espesor = float(Diametro_Medio_de_tubo/temp_E14)# Cesp = Dm/Esp
print("Condición de espesor",Condicion_Espesor)
#--------------------------------------------------------------------------------------------------------------------------
#Resistencia de materiales / Presión 
Presion_maxima = 1.01*10**5 # Pascales (Obtenido de simulación)
Pmax = 14.70 #PSI
#--------------------------------------------------------------------------------------------------------------------------
#Resistencia de materiales/ Esfuerzo por presión
#Esfuezo Tangencial
if Condicion_Espesor > 20:
    Esfuerzo_Tangencial= Presion_maxima*temp_E15/temp_E14
else:
    Esfuerzo_Tangencial = Presion_maxima*((temp_E13/2)**2+temp_E15**2)/((temp_E13/2)**2-temp_E15**2)
print("Esfuerzo tangencial",Esfuerzo_Tangencial,"Pa")
#Esfuerzo Longitudinal
if Condicion_Espesor > 20:
    Esfuerzon_Longitudinal = Presion_maxima*temp_E15/2*temp_E14
else :
    Esfuerzon_Longitudinal = Presion_maxima*temp_E15**2/((temp_E13/2)**2-temp_E15**2)
print("Esfuerzo longitudinal",Esfuerzon_Longitudinal,"Pa")
#Esfuerzo Radial
if Condicion_Espesor > 20:
    Esfuerzo_Radial= 0
else:
    Esfuerzo_Radial = -Presion_maxima
print("Esfuerzo Radial",Esfuerzo_Radial,"Pa")
#Esfuerzo Maximo
if Esfuerzo_Tangencial > Esfuerzo_Radial:
    Esfuerzo_Maximo = Esfuerzo_Tangencial
else:
    Esfuerzo_Maximo = Esfuerzo_Radial
print ("Esfuerzo Maximo", Esfuerzo_Maximo,"Pa")
#Margen de Seguridad
temp_E20 = 2.75*10**8 
n=temp_E20/Esfuerzo_Maximo
print("Margen Seguridad",n,)
#----------------------------------------------------------------------------------------
#Resistencia de Materiales, Determinación de Areas afectadas por tornillos
Numero_tornillos= 6
Diametro_Tornillos=0.009
Distancia_centro_tornillo_pared=0.01
#Area_Transversal_tubo
Area_Transversal_tubo = pi*((temp_E13/2)**2-temp_E15**2)
print("Area Transversal",Area_Transversal_tubo,"m^2")
#Area de sector circular
Angulo_sector_circular= arcsin((Diametro_Tornillos/2)/temp_E15)
print("Angulosector circular",Angulo_sector_circular*(180/pi)," grados")
#Area transversal de 1 tornillo
Area_Transversal_1_tornillo= (Angulo_sector_circular/2)*((temp_E13/2)**2-temp_E15**2-temp_E14**2)
print("Area transversal de un tornillo",Area_Transversal_1_tornillo,"m^2")
#Area transversal ocupada por los tornillos
Area_trnasversal_Tornillos = Area_Transversal_1_tornillo*Numero_tornillos
print("Area Transversal de los tornilos", Area_trnasversal_Tornillos,"m^2")
#Area de material
Area_Material = Area_Transversal_tubo-Area_trnasversal_Tornillos
print("Area de Material",Area_Material,"m^2")
#Espesor del segmento cortante
Espesor_segemento_cortante = Distancia_centro_tornillo_pared-(Diametro_Tornillos/2)
print("Espesor de segmento cortante",Espesor_segemento_cortante,"m")