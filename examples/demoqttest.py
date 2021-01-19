from PySide2 import QtWidgets

import demoqtlibbinding

a = QtWidgets.QApplication()

q = demoqtlibbinding.DemoQtClass()
q.setValue(110)
print(q.value())
q.setValues((1,2,3))
print(q.values())
q.setStdValues([4,5,6])
print(q.values())
