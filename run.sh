#!/usr/bin/env bash

echo "================================================"
echo "This requires libtiledb installed in /opt/tiledb"
echo "================================================"
echo ""

python3 -m venv venv
source venv/bin/activate
pip install -r requirements.txt
python setup.py develop
pytest --capture=no tests.py
