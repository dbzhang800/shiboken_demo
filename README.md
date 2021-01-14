## Introduction

This project is used to show how to use shiboken2 to create python bindings for custom cpp and/or Qt libraries.

## Build

#### Requrie

* Python (3.5 3.6 3.7 3.8 3.9)
* Qt (5.15) [Skip this if you care about non-Qt lib only]
* Visual Studio (2015 2017 2019) [Windows]
* Cmake (3.1 or newer)


* pyside2 (5.15)
* shiboken2 (5.15)
* `shiboken2_generator`(5.15) 

```
pip install --index-url=http://download.qt.io/official_releases/QtForPython/ --trusted-host download.qt.io  shiboken2 pyside2 shiboken2_generator
```

