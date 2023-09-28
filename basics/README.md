# C++ Basics

### Prerequisites

* Install boost on macOs
```shell
brew install boost 
```

* Edit cpp properties file
```json
"configurations": [
    {
        ...
        "includePath": [
            "${workspaceFolder}/**",
            "/opt/homebrew/Cellar/boost/1.82.0_1/**",
            "/opt/homebrew/Cellar/boost/1.82.0_1/include/",
            "/opt/homebrew/Cellar/boost/1.82.0_1/lib/",
        ],
        ...
    }
],
```

_Obs: the path /opt/homebrew/Cellar/boost/1.82.0_1/** is here the boost is installed on macos with brew_

### Usage

* Compile
```shell
g++ basics.cpp -I /opt/homebrew/Cellar/boost/1.82.0_1/include
```

* Execute code
```shell
./a.out
```