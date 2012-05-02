/**
 *	\file	graphisme.c
 *	\brief	D�finition des m�thodes d'affichage et de gestion de clavier.
 */

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include "graphics.h"


/**
 *	\fn	void ModeRaw(int activer)
 *	\brief	Active ou d�sactive le mode Raw.
 *	Activer le mode Raw permet de r�cup�rer les appuis de touche
 * 	du clavier sans avoir � appuyer sur Entr�e. 
 *	Vous devez commencer votre programme en activant le mode Raw,
 *	et le d�sactiver avant de terminer le programme.
 *	\param	activer	0 pour d�sactiver, autre pour activer.
 *	\see	void ActiverModeRaw()
 *	\see	void DesactiverModeRaw()
 *	\see	int RecupererAppuiTouche()
 */
void ModeRaw(int activer)
{
    static struct termios cooked;
    static int raw_actif = 0;
    
    if (raw_actif == activer)
        return;
    
    if (activer)
    {
        struct termios raw;
        
        tcgetattr(STDIN_FILENO, &cooked);
        
        raw = cooked;
        cfmakeraw(&raw);
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
    }
    else
        tcsetattr(STDIN_FILENO, TCSANOW, &cooked);
    
    raw_actif = activer;
}

/**
 *	\fn	void ActiverModeRaw()
 *	\brief	Active le mode Raw.
 *	\see	int ModeRaw()
 */
void ActiverModeRaw()
{
	ModeRaw(1);
}

/**
 *	\fn	void ActiverModeRaw()
 *	\brief	D�sactive le mode Raw.
 *	\see	int ModeRaw()
 */
void DesactiverModeRaw()
{
	ModeRaw(0);
}

/**
 *	\fn		void EffacerEcran();
 *	\brief	Efface la console.
 */
void EffacerEcran()
{
	printf("\033[H\033[2J");
}


/**
 *	\fn		void ChangerCouleurTexte(int couleur)
 *	\brief	Change la couleur courante du texte.
 *	\param	couleur	La nouvelle couleur de texte.
 */
void ChangerCouleurTexte(int couleur)
{
	printf("\033[%dm",couleur);
}

/**
 *	\fn		void ChangerCouleurFond(int couleur)
 *	\brief	Change la couleur courante du fond.
 *	\param	couleur	La nouvelle couleur de fond.
 */
void ChangerCouleurFond(int couleur)
{
	printf("\033[%dm",couleur+10);
}

/**
 *	\fn		void ReinitialiserCouleur()
 *	\brief	R�initalise les couleurs de texte et de fond.
 */
void ReinitialiserCouleur()
{
	printf("\033[%dm",0);
}

/**
 *	\fn		void SePositionner(unsigned int x, unsigned int y)
 *	\brief	Se positionne dans la console.
 *	\param	x	L'abscisse du curseur.
 *	\param	y	L'ordonn�e du curseur.
 */
void SePositionner(unsigned int x, unsigned int y)
{
	printf("\033[%u;%uH", y, x);
}


/**
 *	\fn		int RecupererAppuiTouche()
 *	\brief	R�cup�re le prochain appui de touche.
 *	\return	Un entier correspondant � la touche.
 *	\see	ToucheClavier
 */
int RecupererAppuiTouche()
{
	int c = fgetc(stdin);
	switch (c)
	{
		/* Caract�res non imprimables. */
		case 9  : return TOUCHE_TABULATION_HORIZONTALE;
		case 13 : return TOUCHE_ENTREE;
		//case 27 : return TOUCHE_ECHAP;
		case 32 : return TOUCHE_ESPACE;
		case 127 : return TOUCHE_RETOUR_ARRIERE;
		/* Caract�res sp�ciaux. */
		case 33 : return TOUCHE_EXCLAMATION;
		case 34 : return TOUCHE_GUILLEMETS;
		case 35 : return TOUCHE_DIESE;
		case 36 : return TOUCHE_DOLLAR;
		case 37 : return TOUCHE_POURCENTAGE;
		case 38 : return TOUCHE_ESPERLUETTE;
		case 39 : return TOUCHE_APOSTROPHE;
		case 40 : return TOUCHE_PARENTHESE_GAUCHE;
		case 41 : return TOUCHE_PARENTHESE_DROITE;
		case 42 : return TOUCHE_ASTERISQUE;
		case 43 : return TOUCHE_PLUS;
		case 44 : return TOUCHE_VIRGULE;
		case 45 : return TOUCHE_MOINS;
		case 46 : return TOUCHE_POINT;
		case 47 : return TOUCHE_SLASH;
		case 58 : return TOUCHE_DOUBLE_POINTS;
		case 59 : return TOUCHE_POINT_VIRGULE;
		case 60 : return TOUCHE_CHEVRON_GAUCHE;
		case 61 : return TOUCHE_EGAL;
		case 62 : return TOUCHE_CHEVRON_DROIT;
		case 63 : return TOUCHE_INTERROGATION;
		case 64 : return TOUCHE_AROBASE;
		case 91 : return TOUCHE_CROCHET_GAUCHE;
		case 92 : return TOUCHE_ANTISLASH;
		case 93 : return TOUCHE_CROCHET_DROIT;
		case 94 : return TOUCHE_ACCENT_CIRCONFLEXE;
		case 95 : return TOUCHE_UNDERSCORE;
		case 96 : return TOUCHE_ACCENT_GRAVE;
		case 123 : return TOUCHE_ACCOLADE_GAUCHE;
		case 124 : return TOUCHE_BARRE_VERTICALE;
		case 125 : return TOUCHE_ACCOLADE_DROITE;
		case 126 : return TOUCHE_TILDE;
		/* Chiffres */
		case 48 : return TOUCHE_ZERO;
		case 49 : return TOUCHE_UN;
		case 50 : return TOUCHE_DEUX;
		case 51 : return TOUCHE_TROIS;
		case 52 : return TOUCHE_QUATRE;
		case 53 : return TOUCHE_CINQ;
		case 54 : return TOUCHE_SIX;
		case 55 : return TOUCHE_SEPT;
		case 56 : return TOUCHE_HUIT;
		case 57 : return TOUCHE_NEUF;
		/* Lettres majuscules. */
		case 65 : return TOUCHE_A_MAJ;
		case 66 : return TOUCHE_B_MAJ;
		case 67 : return TOUCHE_C_MAJ;
		case 68 : return TOUCHE_D_MAJ;
		case 69 : return TOUCHE_E_MAJ;
		case 70 : return TOUCHE_F_MAJ;
		case 71 : return TOUCHE_G_MAJ;
		case 72 : return TOUCHE_H_MAJ;
		case 73 : return TOUCHE_I_MAJ;
		case 74 : return TOUCHE_J_MAJ;
		case 75 : return TOUCHE_K_MAJ;
		case 76 : return TOUCHE_L_MAJ;
		case 77 : return TOUCHE_M_MAJ;
		case 78 : return TOUCHE_N_MAJ;
		case 79 : return TOUCHE_O_MAJ;
		case 80 : return TOUCHE_P_MAJ;
		case 81 : return TOUCHE_Q_MAJ;
		case 82 : return TOUCHE_R_MAJ;
		case 83 : return TOUCHE_S_MAJ;
		case 84 : return TOUCHE_T_MAJ;
		case 85 : return TOUCHE_U_MAJ;
		case 86 : return TOUCHE_V_MAJ;
		case 87 : return TOUCHE_W_MAJ;
		case 88 : return TOUCHE_X_MAJ;
		case 89 : return TOUCHE_Y_MAJ;
		case 90 : return TOUCHE_Z_MAJ;
		/* Lettres minuscules. */
		case 97 : return TOUCHE_A_MIN;
		case 98 : return TOUCHE_B_MIN;
		case 99 : return TOUCHE_C_MIN;
		case 100 : return TOUCHE_D_MIN;
		case 101 : return TOUCHE_E_MIN;
		case 102 : return TOUCHE_F_MIN;
		case 103 : return TOUCHE_G_MIN;
		case 104 : return TOUCHE_H_MIN;
		case 105 : return TOUCHE_I_MIN;
		case 106 : return TOUCHE_J_MIN;
		case 107 : return TOUCHE_K_MIN;
		case 108 : return TOUCHE_L_MIN;
		case 109 : return TOUCHE_M_MIN;
		case 110 : return TOUCHE_N_MIN;
		case 111 : return TOUCHE_O_MIN;
		case 112 : return TOUCHE_P_MIN;
		case 113 : return TOUCHE_Q_MIN;
		case 114 : return TOUCHE_R_MIN;
		case 115 : return TOUCHE_S_MIN;
		case 116 : return TOUCHE_T_MIN;
		case 117 : return TOUCHE_U_MIN;
		case 118 : return TOUCHE_V_MIN;
		case 119 : return TOUCHE_W_MIN;
		case 120 : return TOUCHE_X_MIN;
		case 121 : return TOUCHE_Y_MIN;
		case 122 : return TOUCHE_Z_MIN;
		/* Touches vraiment sp�ciales. */
		case 27 :
		{
			c = fgetc(stdin);
			switch (c)
			{
				case 91 : 
				{
					c = fgetc(stdin);
					switch (c)
					{
						case 49 : 
						{
							c = fgetc(stdin);
							switch (c)
							{
								case 55 :
								{
									c = fgetc(stdin);
									switch (c)
									{
										case 126 : return TOUCHE_F6;
									}
									break;
								}
								case 56 :
								{
									c = fgetc(stdin);
									switch (c)
									{
										case 126 : return TOUCHE_F7;
									}
									break;
								}
								case 57 :
								{
									c = fgetc(stdin);
									switch (c)
									{
										case 126 : return TOUCHE_F8;
									}
									break;
								}
								case 126 : return TOUCHE_ORIGINE;
							}
							break;
						}
						case 50 : 
						{
							c = fgetc(stdin);
							switch (c)
							{
								case 48 :
								{
									c = fgetc(stdin);
									switch (c)
									{
										case 126 : return TOUCHE_F9;
									}
									break;
								}
								case 49 :
								{
									c = fgetc(stdin);
									switch (c)
									{
										case 126 : return TOUCHE_F10;
									}
									break;
								}
								case 51 :
								{
									c = fgetc(stdin);
									switch (c)
									{
										case 126 : return TOUCHE_F11;
									}
									break;
								}
								case 52 :
								{
									c = fgetc(stdin);
									switch (c)
									{
										case 126 : return TOUCHE_F12;
									}
									break;
								}
								case 126 : return TOUCHE_INSERTION;
							}
							break;
						}
						case 51 :
						{
							c = fgetc(stdin);
							switch (c)
							{
								case 126 : return TOUCHE_ECHAP; 
							}
							break;
						}
						case 52 :
						{
							c = fgetc(stdin);
							switch (c)
							{
								case 126 : return TOUCHE_FIN; 
							}
							break;
						}
						case 53 :
						{
							c = fgetc(stdin);
							switch (c)
							{
								case 126 : return TOUCHE_PAGE_PRECEDENTE; 
							}
							break;
						}
						case 54 :
						{
							c = fgetc(stdin);
							switch (c)
							{
								case 126 : return TOUCHE_PAGE_SUIVANTE; 
							}
							break;
						}
						case 65 : return TOUCHE_FLECHE_HAUT;
						case 66 : return TOUCHE_FLECHE_BAS;
						case 67 : return TOUCHE_FLECHE_DROITE;
						case 68 : return TOUCHE_FLECHE_GAUCHE;
						case 71 : return TOUCHE_CINQ_PAVE_NUMERIQUE;
						case 91 : 
						{
							c = fgetc(stdin);
							switch (c)
							{
								case 65 : return TOUCHE_F1;
								case 66 : return TOUCHE_F2;
								case 67 : return TOUCHE_F3;
								case 68 : return TOUCHE_F4;
								case 69 : return TOUCHE_F5;
							}
							break;
						}
					}
					break;
				}
			}
			break;
		}
		case 194 : 
		{
			c = fgetc(stdin);
			switch (c)
			{
				case 163 : return TOUCHE_LIVRE;
				case 164 : return TOUCHE_DEVISE_GENERIQUE;
				case 167 : return TOUCHE_SECTION;
				case 168 : return TOUCHE_ACCENT_TREMA;
				case 176 : return TOUCHE_ACCENT_ROND;
				case 178 : return TOUCHE_PUISSANCE_DEUX;
			}
			break;
		}
		case 195 : 
		{
			c = fgetc(stdin);
			switch (c)
			{
				case 160 : return TOUCHE_A_MIN_GRAVE;
				case 161 : return TOUCHE_A_MIN_AIGU;
				case 162 : return TOUCHE_A_MIN_CIRCONFLEXE;
				case 163 : return TOUCHE_A_MIN_TILDE;
				case 164 : return TOUCHE_A_MIN_TREMA;
				case 165 : return TOUCHE_A_MIN_ROND;
				case 166 : return TOUCHE_AE_MIN;
				case 167 : return TOUCHE_C_CEDILLE;
				case 168 : return TOUCHE_E_MIN_GRAVE;
				case 169 : return TOUCHE_E_MIN_AIGU;
				case 170 : return TOUCHE_E_MIN_CIRCONFLEXE;
				case 171 : return TOUCHE_E_MIN_TREMA;
				case 172 : return TOUCHE_I_MIN_GRAVE;
				case 173 : return TOUCHE_I_MIN_AIGU;
				case 174 : return TOUCHE_I_MIN_CIRCONFLEXE;
				case 175 : return TOUCHE_I_MIN_TREMA;
				case 176 : return TOUCHE_ED_MIN;
				case 177 : return TOUCHE_N_MIN_TILDE;
				case 178 : return TOUCHE_O_MIN_GRAVE;
				case 179 : return TOUCHE_O_MIN_AIGU;
				case 180 : return TOUCHE_O_MIN_CIRCONFLEXE;
				case 181 : return TOUCHE_O_MIN_TILDE;
				case 182 : return TOUCHE_O_MIN_TREMA;
				case 183 : return TOUCHE_DIVISION;
				case 184 : return TOUCHE_O_BARRE;
				case 185 : return TOUCHE_U_MIN_GRAVE;
				case 186 : return TOUCHE_U_MIN_AIGU;
				case 187 : return TOUCHE_U_MIN_CIRCONFLEXE;
				case 188 : return TOUCHE_U_MIN_TREMA;
				case 189 : return TOUCHE_Y_MIN_AIGU;
				case 190 : return TOUCHE_THORN_MIN;
				case 191 : return TOUCHE_Y_MIN_TREMA;
			}
			break;
		}
		case 226 : 
		{
			c = fgetc(stdin);
			switch (c)
			{
				case 130 : 
				{
					c = fgetc(stdin);
					switch (c)
					{
						case 172 : return TOUCHE_EURO;
					}
					break;
				}
			}
			break;
		}
		case 233 : 
		{
			c = fgetc(stdin);
			switch (c)
			{
				case 133 : 
				{
					c = fgetc(stdin);
					switch (c)
					{
						case 146 : return TOUCHE_KANJI_JAPONAIS_SAKE;
					}
					break;
				}
				case 173 : 
				{
					c = fgetc(stdin);
					switch (c)
					{
						case 154 : return TOUCHE_KANJI_JAPONAIS_SAKANA;
					}
					break;
				}
			}
			break;
		}
	}
	return TOUCHE_INCONNUE;
}



