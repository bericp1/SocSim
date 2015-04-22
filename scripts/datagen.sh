#!/usr/bin/env bash

cd ./res
python -m SimpleHTTPServer &
python -mwebbrowser http://localhost:8000/datagen.html