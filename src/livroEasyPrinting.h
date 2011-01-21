// Class automatically generated by Dev-C++ New Class wizard

#ifndef LIVROEASYPRINTING_H
#define LIVROEASYPRINTING_H

#include <htmprint.h> // inheriting class's header file

/*
 * No description
 */
class livroEasyPrinting : public wxHtmlEasyPrinting
{
	public:
		// class constructor
		livroEasyPrinting(const wxString& name = wxT("Printing"), wxWindow *parentWindow = NULL);
		// class destructor
		virtual ~livroEasyPrinting();

    // met � jour la config � partir des donn�es relues en base de config / cf. ParamManager
    void UpdateConfig();


	protected:
        virtual bool DoPreview(wxHtmlPrintout *printout1, wxHtmlPrintout *printout2);

    private:
        wxString m_livroName;   // redefinition de wxHtmlEasyPrinting::m_Name qui est private ...
};

#endif // LIVROEASYPRINTING_H