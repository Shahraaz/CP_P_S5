pushd ..\..\problems\accurate-movement\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\bad-treap\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\cross-stitch\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\double-palindrome\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\equidistant\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\foreach\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\golf\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\high\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\ideal\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\just-the-last-digit\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\kingdom\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\lengths\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

pushd ..\..\problems\managing\statements\english
for %%i in (*.mp) do (
    echo mpost %%i || goto error
)
del /F /Q *.log
popd

latex statements.tex
latex statements.tex || goto error
dvips statements.dvi || goto error
dvipdfmx -p a4 statements.dvi || goto error

latex tutorials.tex
latex tutorials.tex || goto error
dvips tutorials.dvi || goto error
dvipdfmx -p a4 tutorials.dvi || goto error

del /F /Q *.log
del /F /Q *.aux
del /F /Q *.dvi
del /F /Q *.ps

goto ok

:error
echo [ERROR]: Can't compile/build statements/tutorials.
exit 1

:ok
echo [INFO]: Statements/tutorials have been compiled/build.
