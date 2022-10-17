#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>


//void Write()
//{
//    std::ofstream out{ "data.txt" };
//    out << "Hello world!" << std::endl;
//    out << 10 << std::endl;
//    out.close();
//}
//
//void Read()
//{
//    std::ifstream Input;//{ "data.txt" };
//    Input.open("data.txt");
//
//    /*if (!Input.is_open())
//    {
//        std::cout << "Could not open the file!" << std::endl;
//        return;
//    }*/
//
//    if (Input.fail())
//    {
//        std::cout << "Could not open the file!" << std::endl;
//    }
//
//    std::string Message;
//    std::getline(Input, Message);
//
//    int Value{};
//    Input >> Value;
//    Input >> Value;
//
//    if (Input.eof())
//    {
//        std::cout << "End of file encountered!" << std::endl;
//    }
//    if (Input.good())
//    {
//        std::cout << "I/O operations are successful!" << std::endl;
//    }
//    else
//    {
//        std::cout << "Some I/O operations failed!" << std::endl;
//    }
//
//    Input.setstate(std::ios::failbit);
//    Input.clear();
//    Input.close();
//
//    std::cout << Message << " : " << Value << std::endl;
//}


//void Write()
//{
//    std::ofstream out("test.txt");
//    if (!out)
//    {
//        std::cout << "Could not open file for writing!" << std::endl;
//        return;
//    }
//
//    std::string message{ "C++ was invented by Bjarne" };
//
//    for (char ch : message)
//    {
//        out.put(ch);
//    }
//    out.seekp(5);
//    out.put('#');
//}
//
//void Read()
//{
//    std::ifstream input("test.txt");
//
//    if (!input)
//    {
//        std::cout << "Source file not found!" << std::endl;
//        return;
//    }
//
//    input.seekg(0, std::ios::beg);
//    std::cout << "Current position is : " << input.tellg() << std::endl;
//
//    char ch{};
//
//    while (input.get(ch))
//    {
//        std::cout << ch;
//    }
//    std::cout << std::endl;
//}
//
//void UseFstream()
//{
//    std::fstream stream("file.txt");
//
//    if (!stream)
//    {
//        std::ofstream out("file.txt");
//        out.close();
//        stream.open("file.txt");
//    }
//
//    stream << "Hello world" << std::endl;
//
//    stream.seekg(0);
//    std::string line;
//    std::getline(stream, line);
//    std::cout << line << std::endl;
//}

//struct Record
//{
//    int id;
//    char name[10];
//};
//
//void WriteRecord(Record* p)
//{
//    std::ofstream binstream{ "records", std::ios::binary | std::ios::out };
//    binstream.write((const char*)p, sizeof(Record));
//}
//
//Record GetRecord()
//{
//    std::ifstream input{ "records",  std::ios::binary | std::ios::in };
//    Record r;
//    input.read((char*)&r, sizeof(Record));
//    return r;
//}


bool CopyFile(std::string& SourceFilename, std::string DestinationFilename = "")
{
    using namespace std::filesystem;

    if (SourceFilename == "")
    {
        std::cout << "SourceFilename is empty! Please check the Source filename." << std::endl;
        return false;
    }

    path Source(current_path());
    Source /= SourceFilename;

    path Destination(current_path());
    if (DestinationFilename == "")
    {
        DestinationFilename = SourceFilename;
        //DestinationFilename.insert(DestinationFilename.find('.'), "_copy");
        Destination /= DestinationFilename;
    }
    else
    {
        Destination /= DestinationFilename;
    }

    std::ifstream input_stream{ Source, std::ios::in | std::ios::binary };
    if (!input_stream)
    {
        std::cout << "Source file not found!" << std::endl;
        return false;
    }

    if (exists(Destination))
    {
        std::cout << "Do you want to override " << DestinationFilename << "?" << std::endl;
        char UserReply{};
        std::cin >> UserReply;

        if (std::toupper(UserReply) != 'Y')
        {
            std::cout << "Copy operation cancelled by user!" << std::endl;
            return false;
        }
    }

    std::ofstream out_stream{ Destination, std::ios::out | std::ios::binary };

    auto SourceFileSize = file_size(Source);
    const unsigned int BufferSize = 512;
    char Buffer[BufferSize];

    std::cout << "Copying started : ";

    if (SourceFileSize < BufferSize)
    {
        if (!input_stream.read(Buffer, SourceFileSize))
        {
            throw std::runtime_error("Error occurred during read operation");
        }
        if (!out_stream.write(Buffer, SourceFileSize))
        {
            throw std::runtime_error("Error occurred during write operation");
        }
    }
    else
    {
        auto ChunksNum = SourceFileSize / BufferSize;
        auto RemainingSize = SourceFileSize % BufferSize;

        int Progress{};
        int PrevProgress{};

        for (int i(0); i < ChunksNum; ++i)
        {
            if (!input_stream.read(Buffer, BufferSize))
            {
                throw std::runtime_error("Error occurred during read operation");
            }
            if (!out_stream.write(Buffer, BufferSize))
            {
                throw std::runtime_error("Error occurred during write operation");
            }

            Progress = (int)(10 * ((float)i / ChunksNum));
            if (Progress != PrevProgress)
            {
                std::cout << ".";
            }
            PrevProgress = Progress;
        }

        memset(Buffer, '\0', BufferSize);

        //Read and write the remaining bytes
        if (RemainingSize > 0) {
            if (!input_stream.read(Buffer, RemainingSize))
            {
                throw std::runtime_error("Error occurred during read operation");
            }
            if (!out_stream.write(Buffer, RemainingSize))
            {
                throw std::runtime_error("Error occurred during write operation");
            }
            std::cout << ". ";
        }
    }

    std::cout << "Copy done!" << std::endl;

    input_stream.close();
    out_stream.close();

    std::cout << "Source file size : " << SourceFileSize << std::endl;
    std::cout << "Copied file size : " << file_size(Destination) << std::endl;

    return true;
}


int main()
{
    std::string Src("testcopy");

    //std::ofstream BinaryStream{ Src, std::ios::binary | std::ios::out };
    //for (int i(0); i < 50000; ++i)
    //{
    //    int num{ 12345678 };
    //    BinaryStream.write((const char*)&num, sizeof(num));
    //}

    //BinaryStream.close();

    CopyFile(Src);


  /*  Record r;
    r.id = 1001;
    strcpy_s(r.name, 10, "C++");
    WriteRecord(&r);

    Record r2 = GetRecord();
    std::cout << r2.id << " " << r2.name << std::endl;*/

    //std::ofstream textstream{ "data" };
    //textstream << 12345678;

    //std::ofstream binarystream{ "binary", std::ios::binary | std::ios::out };
    //int num{ 12345678 };
    //binarystream.write((const char*)&num, sizeof(num));

    //std::ifstream input{ "binary", std::ios::binary | std::ios::in };
    //input.read((char*)&num, sizeof(num));

    //std::cout << num << std::endl;

    //UseFstream();

    //Write();
    //Read();

   /* using namespace std::filesystem;
    path source(current_path());
    source /= "Section11.cpp";

    std::ifstream input{ source };
    if (!input)
    {
        std::cout << "Source file not found!" << std::endl;
        return -1;
    }

    path destination(current_path());
    destination /= "Copy.cpp";

    std::ofstream output{ destination };

    std::string line;

    while (!std::getline(input, line).eof())
    {
        output << line << std::endl;
    }

    input.close();
    output.close();*/



   /* Write();
    Read();*/

    /*using namespace std::filesystem;

    path p{ R"(D:\Courses\CompleteModernCpp\Section11\)" };

    if (p.has_filename())
    {
        std::cout << p.filename() << std::endl;
    }

    for (const auto& x : p)
    {
        std::cout << x << std::endl;
    }

    directory_iterator beg{ p };
    directory_iterator end{};

    while (beg != end)
    {
        std::cout << *beg << std::endl;
        ++beg;
    }*/

    //std::string Filename{ R"(D:\Courses\CompleteModernCpp\Section11\newfile.txt)" };
    //std::cout << Filename << std::endl;

    //std::string Message{ R"MSG(C++ introduced filesystem API"(In C++ 17)")MSG" };
    //std::cout << Message << std::endl;

    return 0;
}
