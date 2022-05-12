#include <EBEventLoop.hpp>
#include <EBPrinter.hpp>
#include <EBDirectory.hpp>
#include <profile/EBLogger.hpp>

using namespace EBCpp;

int main(int argc, char **argv)
{

    if (argc != 3)
    {
        EB_LOG_INFO("Usage: PrintImages \"{PRINTERNAME}\" \"{DIRECTORY}\"");
        EB_LOG_INFO("----------------------------------------------------------------------");
        EB_LOG_INFO("Printer List:");
        EBList<EBString> list = EBPrinter::getPrinterList();
        for (auto l : list)
        {
            EB_LOG_INFO("\t" << l.get());
        }
        EB_LOG_INFO("----------------------------------------------------------------------");
        return 1;
    }
    else
    {
        EBString printerName(argv[1]); //"Microsoft Print to PDF");
        EBString directory(argv[2]);   //"C:\\Users\\tropby\\Pictures\\");
        EB_LOG_INFO("Starting with printer " << printerName);

        EBList<EBString> dir = EBDirectory::getDirectoryList(directory);
        for (auto l : dir)
        {
            if (
                l.get().toLower().endsWith(".jpg") ||
                l.get().toLower().endsWith(".png"))
            {
                EB_LOG_INFO("Now printing: " << l.get());
                if (EBPrinter::printImage(l.get(), printerName))
                {
                    EB_LOG_INFO("Printing OKAY!");
                }
                else
                {
                    EB_LOG_INFO("Printing ERROR!");
                    return 2;
                }
            }
        }
        return 0;
    }   
}