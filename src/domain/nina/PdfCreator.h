#ifndef NINA_DOMAIN_PDFCREATOR_H
#define NINA_DOMAIN_PDFCREATOR_H

// STL includes
#include <string>
#include <vector>

// BOOST includes
#include <boost/filesystem.hpp>

// Fwd declarations
namespace nina { namespace domain { class Invoice; } }



namespace nina {
namespace domain {

class PdfCreator
{
  public:
    PdfCreator();
    ~PdfCreator();

  public:
    /// \brief Creates the PDF file
    ///
    /// \param[in]  invoice The invoice data to be rendered as PDF
    /// \param[out] errorMsg In case an error occurs this variable will contain the error text
    ///
    /// \return Path to the PDF file
    ///
    boost::filesystem::path operator()(const Invoice& invoice, std::string& errorMsg);

  private:
    void createWorkingDir() ;
    boost::filesystem::path getTmpFilename() const;
    void removeWorkingDir();
    void writeRComFile();
    boost::filesystem::path WriteLatexFile(const Invoice& invoice);
    std::string createPdf(const boost::filesystem::path& path);

  private:
    boost::filesystem::path m_workingDir;
};

} // End namespace domain
} // End namespace nina

#endif  // NINA_DOMAIN_PDFCREATOR_H
