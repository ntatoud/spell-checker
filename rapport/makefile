####MAKEFILE POUR LE RAPPORT#####
TEX=pdflatex
PDF_DIR=PDF
TAD_DIR=TAD
CON_DIR=Conception

#.PHONY : all proper tad conception clean cleanPDF cleanTEX #Pour ne pas confondre commandes & fichiers

#Faire le rapport & supprime les residus de compilation
all : cleanPDF $(PDF_DIR)/tad.pdf cleanTEX $(PDF_DIR)/conception.pdf cleanTEX $(PDF_DIR)/rapport.pdf cleanTEX

#2e passe sur le rapport, pour faire le sommaire
proper :
	$(TEX) -output-directory=$(PDF_DIR) rapport.tex

#Rapport rapide : sans 2e passe
fast : $(PDF_DIR)/rapport.pdf cleanTEX

#Seulement les TAD & supprime les residus de compilation
tad : $(PDF_DIR)/tad.pdf cleanTEX

#Seulement la conception & supprime les residus de compilation
conception : $(PDF_DIR)/conception.pdf cleanTEX

#Conception: tex -> pdf
$(CON_DIR)/%.pdf : $(CON_DIR)/%.tex
	$(TEX) -output-directory=$(CON_DIR) $<

#TAD: tex -> pdf
$(TAD_DIR)/%.pdf : $(TAD_DIR)/%.tex
	$(TEX) -output-directory=$(TAD_DIR) $<

#Commande pour les TAD
$(PDF_DIR)/tad.pdf : $(TAD_DIR)/TAD_Mot.pdf $(TAD_DIR)/TAD_FichierTexte.pdf $(TAD_DIR)/TAD_CorrecteurOrthographique.pdf $(TAD_DIR)/TAD_Dictionnaire.pdf 
	$(TEX) -output-directory=$(PDF_DIR) tad.tex

#Commande pour la conception
$(PDF_DIR)/conception.pdf : $(CON_DIR)/C_Mot.pdf $(CON_DIR)/C_FichierTexte.pdf $(CON_DIR)/C_CorrecteurOrthographique.pdf $(CON_DIR)/C_Dictionnaire.pdf 
	$(TEX) -output-directory=$(PDF_DIR) conception.tex

#Commande pour le rapport
$(PDF_DIR)/rapport.pdf : $(TAD_DIR)/TAD_Mot.pdf $(TAD_DIR)/TAD_FichierTexte.pdf $(TAD_DIR)/TAD_CorrecteurOrthographique.pdf $(TAD_DIR)/TAD_Dictionnaire.pdf
	$(TEX) -output-directory=$(PDF_DIR) rapport.tex

#Supprime les résidus latex
cleanTEX :
	find . -type f -name "*.log" -delete
	find . -type f -name "*.out" -delete
	find . -type f -name "*.aux" -delete
	find . -type f -name "*.toc" -delete

#Supprime les PDF
cleanPDF :
	rm -rf PDF/*.pdf
	rm -rf TAD/*.pdf
	rm -rf Conception/*.pdf

#Supprime tout
clean : cleanTEX cleanPDF
