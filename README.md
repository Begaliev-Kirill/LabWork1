# LabWork1
## Author
Begaliev Kirill Evgenievich, 24.B82-mm <br>
st129977@student.spbu.ru , tg: @silly_kat
## Description
Program read the BMP file and rotate it 90 degree clockwise and counterclockwise, apply Gays filter to the last one and save all results
## Build
#### to build project
```bash
make
```
#### To delete only created files 
```bash
make clean
```
#### To delete all created and compiled files
```bash
make cleanall
```
## Run
#### To run program
```bash
./bmp "input_file.bmp" "radiusOfGausMatrix"(ushort) "sigma"(float)
```
"input_file.bmp" is "test-goat.bmp", radiusOfGausMatrix = 7 and sigma = 4.1478 if you don't enter it, you can write 0-3 arguments but in this order only

