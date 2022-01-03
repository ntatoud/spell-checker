####MAKEFILE POUR LE RAPPORT#####
TEX=pdflatex
PDF_DIR=PDF
TAD_DIR=TAD
CON_DIR=Conception
TEX_CONCEPTION=$(CON_DIR)/C_Mot.tex $(CON_DIR)/C_Dictionnaire.tex $(CON_DIR)/C_FichierTexte.tex $(CON_DIR)/C_CorrecteurOrthographique.tex
TEX_TAD=$(TAD_DIR)/TAD_Mot.tex $(TAD_DIR)/TAD_Dictionnaire.tex $(TAD_DIR)/TAD_FichierTexte.tex $(TAD_DIR)/TAD_CorrecteurOrthographique.tex

.PHONY : all proper tad clean cleanPDF cleanTEX conception

#Faire le rapport & supprime les residus de compilation
all : rapport.tex cleanPDF $(PDF_DIR)/rapport.pdf proprer cleaanTEX

#2e passe sur le rapport, pour faire le sommaire
proper : rapport.tex $(TEX_TAD) $(TEX_CONCEPTION)
	$(TEX) -output-directory=$(PDF_DIR) rapport.tex

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
$(PDF_DIR)/tad.pdf : tad.tex $(TEX_TAD)
	$(TEX) -output-directory=$(PDF_DIR) tad.tex

#Commande pour la conception
$(PDF_DIR)/conception.pdf : conception.tex $(TEX_CONCEPTION)
	$(TEX) -output-directory=$(PDF_DIR) conception.tex

#Commande pour le rapport
$(PDF_DIR)/rapport.pdf : rapport.tex $(TEX_TAD) $(TEX_CONCEPTION)
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
	rm -rf AD/*.pdf
	rm -rf images/Volutes1-eps-converted-to.pdf
	rm -rf images/Volutes1Top-eps-converted-to.pdf
	rm -rf images/Volutes3Bottom-eps-converted-to.pdf
	rm -rf images/bandeau_cyan_top-eps-converted-to.pdf


#Supprime tout
clean : cleanTEX cleanPDF
