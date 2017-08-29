@echo �����⮢�� 䠩��� �ਬ�஢ 
@echo ==========================

@echo ��२��������� �।��饣� ��饣� 䠩��

rename .\bib\examples.bib examples.bak

@echo ����஢���� ����� �����쪨� 䠩��� � ���� ����让

copy .\bib\ex*.bib .\bib\examples.bib

@echo ������᪠� ������� �ਬ�஢

for %%f in (gost7*.tex) do pdflatex -quiet %%f 
for %%f in (gost200*.tex) do pdflatex -quiet %%f 

@echo ������᪠� ��ࠡ�⪠ bibtex8 *.aux, ��� �⮣� '�㤠 �� �㤥�'

for %%f in (gost*.aux) do bibtex8 -B -c cp1251.csf %%f 

@echo ������᪠� ������� �ਬ�஢ (��室 ��᫥ bibtex8)

for %%f in (gost7*.tex) do pdflatex %%f 
for %%f in (gost200*.tex) do pdflatex %%f 
for %%f in (gost2008-nat*.tex) do pdflatex %%f 
for %%f in (gost2008-sort*.tex) do pdflatex %%f 

@echo ���⪠ ����� �� ���㦭�� 䠩���

@del *.aux *.out *.toc *.brf .pdf
@del *.bbl 
@del *.blg 
@del *.log
@echo =======
