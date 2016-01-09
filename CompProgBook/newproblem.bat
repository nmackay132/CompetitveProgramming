@echo off
echo Create Folder %1

mkdir %1
cd %1

echo.> %1.cpp
echo.> "input1.txt"
echo.> "output1.txt"

echo.> "input2.txt"
echo.> "output2.txt"

echo.> "input3.txt"
echo.> "output3.txt"

echo.> "input4.txt"
echo.> "output4.txt"

echo.> "res.txt"

:: cd ..
type "C:\Users\macka_000\Documents\Visual Studio 2013\Projects\CompProgBook\CompProgBook\Template.h" >> %1.cpp
:: type Template.h >> %1/%1.cpp
:: copy %1/%1.cpp "C:/Users/macka_000/SkyDrive/Documents/Programming Team/Problems"
:: start "" "C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Visual Studio 2013\Visual Studio 2013.lnk" "C:\Users\macka_000\Documents\Visual Studio 2013\Projects\CompProgBook\CompProgBook\%1\%1.cpp"

:: cd %1
echo.
