#!/bin/bash

rm -rf stl_html
rm -rf stl_html.tar

doxygen doxyfile.txt
tar -cvf stl_html.tar stl_html/