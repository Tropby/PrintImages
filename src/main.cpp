#include <EBEventLoop.hpp>
#include <EBPrinter.hpp>
#include <EBFile.hpp>
#include <EBDirectory.hpp>
#include <profile/EBLogger.hpp>

using namespace EBCpp;

int main(int argc, char **argv)
{
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    ULONG_PTR gdiplusToken;
    GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    if (argc != 3)
    {
        EB_LOG_INFO("Usage: PrintImages \"{PRINTERNAME}\" \"{DIRECTORY}\"");
        EB_LOG_INFO("--------------------------------------------------------");
        EB_LOG_INFO("Printer List:");
        EBList<EBString> list = EBPrinter::getPrinterList();
        for (auto l : list)
        {
            EB_LOG_INFO("\t" << l.get());
        }
        EB_LOG_INFO("--------------------------------------------------------");
        return 1;
    }
    else
    {
        EBString printerName(argv[1]);
        EBString directory(argv[2]);

        EB_LOG_INFO("Starting with printer " << printerName);

        EBList<EBString> dir = EBDirectory::getDirectoryList(directory);
        for (auto l : dir)
        {
            if (
                l.get().toLower().endsWith(".jpg") ||
                l.get().toLower().endsWith(".png"))
            {
                EB_LOG_INFO("Now printing: " << l.get());
                for( int i = 0; i<15; i++)
                {
                    EB_LOG_INFO("SLEEP " << i << " / " << 15);
                    usleep(1000 * 1000);
                }

                if (EBPrinter::printImage(directory + "/" + l.get(), printerName))
                {
                    EB_LOG_INFO("Printing OKAY!");
                    if( EBFile::remove(directory + "/" + l.get()) )
                    {
                        EB_LOG_INFO("File removed successful!");
                    }
                    else
                    {
                        EB_LOG_ERROR("File can not be removed!");
                        system("pause");
                    }
                }
                else
                {
                    EB_LOG_INFO("Printing ERROR!");
                    return 2;
                }
            }
        }

        EB_LOG_INFO("Finished!");
        return 0;
    }   
}