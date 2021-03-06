// Name:        livre_html.h
// Author:      PE EPAILLARD
// Created:     10/27/2004 12:22:10 AM
//
//Copyright PE Epaillard, 10/27/2004
//
//Fougny@gmail.com
//
//Ce logiciel est un programme informatique servant � [rappeler les
//caract�ristiques techniques de votre logiciel].
//
//Ce logiciel est r�gi par la licence CeCILL soumise au droit fran�ais et
//respectant les principes de diffusion des logiciels libres. Vous pouvez
//utiliser, modifier et/ou redistribuer ce programme sous les conditions
//de la licence CeCILL telle que diffus�e par le CEA, le CNRS et l'INRIA
//sur le site "http://www.cecill.info".
//
//En contrepartie de l'accessibilit� au code source et des droits de copie,
//de modification et de redistribution accord�s par cette licence, il n'est
//offert aux utilisateurs qu'une garantie limit�e.  Pour les m�mes raisons,
//seule une responsabilit� restreinte p�se sur l'auteur du programme,  le
//titulaire des droits patrimoniaux et les conc�dants successifs.
//
//A cet �gard  l'attention de l'utilisateur est attir�e sur les risques
//associ�s au chargement,  � l'utilisation,  � la modification et/ou au
//d�veloppement et � la reproduction du logiciel par l'utilisateur �tant
//donn� sa sp�cificit� de logiciel libre, qui peut le rendre complexe �
//manipuler et qui le r�serve donc � des d�veloppeurs et des professionnels
//avertis poss�dant  des  connaissances  informatiques approfondies.  Les
//utilisateurs sont donc invit�s � charger  et  tester  l'ad�quation  du
//logiciel � leurs besoins dans des conditions permettant d'assurer la
//s�curit� de leurs syst�mes et ou de leurs donn�es et, plus g�n�ralement,
//� l'utiliser et l'exploiter dans les m�mes conditions de s�curit�.
//
//Le fait que vous puissiez acc�der � cet en-t�te signifie que vous avez
//pris connaissance de la licence CeCILL, et que vous en avez accept� les
//termes.
//
//---------------------------------------------------------------------------
// Class automatically generated by Dev-C++ New Class wizard

#ifndef LIVRE_HTML_H
#define LIVRE_HTML_H

#ifndef WX_PRECOMP
// Include your minimal set of headers here, or wx.h
#include <wx/wx.h>
#endif

#include <curl/curl.h>
#include <curl/types.h>
#include <curl/easy.h>
#include <wx/ffile.h>
#include <wx/file.h>
#include <wx/xml/xml.h>
#include <wx/listbox.h>
#include "divers.h"


class caracteristiques
{
public:
       //constructor
       caracteristiques();
       //destructeur
       ~caracteristiques();

       // affichage
       wxString Affiche();

       wxString Titre;
       wxString Auteur;
       wxString Editeur;
       wxString Collection;
       wxString Genre;
       wxString Date_parution;
       wxString Langue;
       wxString Traducteur;
       wxString Presentation;
       wxString Nb_pages;
       wxString Isbn;
       wxString Ean;
       wxString Prix;
       wxString Commentaires;
       wxString Url;
       wxString Url_img_r;
       wxString Url_img_v;
};

class liste_caracteristiques : public wxList
{
private:
      wxNode* node;
      int test;
public:
      liste_caracteristiques();
      ~liste_caracteristiques();

      caracteristiques* Suivant();
      void Init_parcours();
      void Effacer();
      void Ajouter(caracteristiques* caract);
};

// No description
class LIVRE_HTML
{
public:
		// class constructor
		LIVRE_HTML();
		// class destructor
		~LIVRE_HTML();
		void Setnum_isbn(wxString x); // sets the value of num_isbn
		wxString Getnum_isbn(); // returns the value of num_isbn
		// No description
		int recupData(wxString url,wxString nom_fichier);
		// No description
		int traiter_isbn(wxString isbn,wxString img_recto,wxString img_verso,caracteristiques& caracte, int type_recherche=0);
		// No description
		int chercher_texte_old(wxString texte,liste_caracteristiques& lCaract,liste_caracteristiques& lCaract2, int type_recherche=0);
        int chercher_texte(wxString texte,liste_caracteristiques& l_livre,int type_recherche);
		//
		void setproxy(bool utiliser, wxString adresse, wxString port, wxString user, wxString pass);
		wxString interieur(wxString sTexte,wxString debut,wxString fin);
        wxString recode_caract(wxString chaine);

private:
        bool prox_utilise;
        wxString prox_adresse;
        int prox_port;
        wxString prox_user;
        wxString prox_pass;

	private:
		// No description
		wxString num_isbn;
		// No description
		wxString nomFichier;
        wxXmlNode * cherche_node(wxString nom_node, wxXmlNode *depart,wxString propriete="", wxString pos_courante="");
        int traiter_isbn_amazon(wxString ws_isbn,wxString img_recto,wxString img_verso,caracteristiques& caract, int type_recherche);
		// gere_amazon_item : gere les items des nodes du fichier ML venant de amazon
		bool gere_amazon_item(wxXmlNode *item_node, liste_caracteristiques& l_carac);
		// No description
		static size_t write_d(void *ptr,size_t size, size_t nmemb, void *stream);
		// No description
		int chercher_TD(wxString texte,wxString texte_a_chercher,wxString& texte_retour,int decalage,bool suppr_balise);
		// No description
		bool trancher(wxString& partie_droite,wxString& partie_gauche,wxString centre);
		// chercher A
		int chercher_A(wxString texte,wxString texte_a_chercher,wxString& texte_retour,int decalage,bool suppr_balise);
		// nouvelle methode parce que alapage ils sont chiants!
        wxString recup_donnee(wxString donnee, wxString debut, wxString fin, int type_recup=0);
};

#endif // LIVRE_HTML_H
