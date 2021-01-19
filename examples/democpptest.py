# Force load proper library such as shiboken
import PySide2

import democpplibbinding

a = democpplibbinding.DemoCppClass()
a.setName("1+1=10")
print(a.name())
print(a.className())
a.setValues((1,2,3))
print(a.values())
democpplibbinding.setGlobalValues((1,2,3))

print(a.allDemoCppClasses())
