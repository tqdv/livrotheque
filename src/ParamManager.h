///-----------------------------------------------------------------
///
/// @file      ParamManager.h
/// @author    
/// Created:   12/12/2009 18:10:19
/// @section   DESCRIPTION
///            ParamManager class declaration
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
//*
///
///------------------------------------------------------------------

#ifndef __PARAMMANAGER_H__
#define __PARAMMANAGER_H__

#include "mabase.h"

class ParamManager;
WX_DECLARE_STRING_HASH_MAP( ParamManager*, MapParamManager );

class ParamManager {
public:
    ParamManager(ma_base& pBaseConfig, wxString cle);
    ~ParamManager();

    static ParamManager* GetInstance(wxString cle);
    
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  wxString& val1, wxString& val2);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  wxString& val1);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  long& val1, long& val2);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  long& val1);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  BOOL& val1, long& val2);
    void GetOrSet(const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  BOOL& val1);
                  
    void Set     (const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  wxString val1, wxString val2="");
    void Set     (const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  BOOL val1);
    void Set     (const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  BOOL val1, long val2);                  
    void Set     (const wxString& tableParam, const wxString& typeParam, const wxString& nomParam, 
                  long val1, long val2=0);
    
                  
private:
    static MapParamManager tabInstance;  // toutes les instances cr��es, associ�es � une chaine de caract�re utilis�e comme cl�
    ma_base& baseConfig;
    wxString m_cle;                 // la cl� utilis�e dans la map tabInstance
    
};



#endif
