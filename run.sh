#!/usr/bin/env bash

if [ -d "./build" ]; then
  rm -rf "./build/"
fi

python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
python setup.py develop
pytest --capture=no tests.py
