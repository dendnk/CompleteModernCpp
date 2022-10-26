#include "Filesystem.h"
#include <iostream>
#include <filesystem>


namespace FS = std::filesystem;

void UsingPath()
{
	// Using the R literal, so we don't need to escape the backslash path separator
	FS::path SelectedPath{ R"(D:\Courses\CompleteModernCpp\18_StandardLibraryComponentsCpp17\Test.docx)" };

	std::cout << SelectedPath << std::endl;
	std::cout << SelectedPath.string() << std::endl; // without double backslashes


	SelectedPath.remove_filename();

	// add new filename

	//SelectedPath.append("Newfilename.dat");
	SelectedPath /= "Newfilename2.dat";


	if (SelectedPath.has_root_name())
		std::cout << "Root name\t : " << SelectedPath.root_name().string() << std::endl;

	if (SelectedPath.has_root_path())
		std::cout << "Root path\t : " << SelectedPath.root_path().string() << std::endl;

	if (SelectedPath.has_root_directory())
		std::cout << "Root directory\t : " << SelectedPath.root_directory().string() << std::endl;

	if (SelectedPath.has_parent_path())
		std::cout << "Parent path\t : " << SelectedPath.parent_path().string() << std::endl;

	if (SelectedPath.has_relative_path())
		std::cout << "Relative path\t : " << SelectedPath.relative_path().string() << std::endl;

	if (SelectedPath.has_filename())
		std::cout << "Filename\t : " << SelectedPath.filename().string() << std::endl;

	if (SelectedPath.has_stem())
		std::cout << "Stem part\t : " << SelectedPath.stem().string() << std::endl;

	if (SelectedPath.has_extension())
		std::cout << "Extension\t : " << SelectedPath.extension().string() << std::endl;
}

void ListDirectory(std::string_view File)
{
	FS::path CurrentPath(File);

	// With iterators
	/*FS::directory_iterator Begin(CurrentPath);
	FS::directory_iterator End{};

	while (Begin != End)
	{
		auto DirectoryEntry = *Begin++;
		std::cout << DirectoryEntry.path().filename() << std::endl;
	}*/

	std::vector<FS::directory_entry> DirectoryEntries{};

	// With for-ranged base loop
	for (const auto& DirectoryEntry : FS::directory_iterator{ CurrentPath })
	{
		DirectoryEntries.push_back(DirectoryEntry);
	}

	// If directory entry will satisfy condition in predicate, then it will go to the front of the container
	std::partition(DirectoryEntries.begin(), DirectoryEntries.end(),
		[](const FS::directory_entry& DirectoryEntry)
		{
			return DirectoryEntry.is_directory();
		});

	for (const auto& DirectoryEntry : DirectoryEntries)
	{
		switch (const auto& Path = DirectoryEntry.path(); DirectoryEntry.status().type()) /* Also could use global functions : FS::status(DirectoryEntry).type()*/
		{
		case FS::file_type::directory:
			std::cout << "[DIR] : " << Path.string() << std::endl;
			break;

		case FS::file_type::regular:
			std::cout << "\t" << Path.string() << '\t' << DirectoryEntry.file_size() << " bytes" << std::endl;
			break;
		}
	}
}

void DirectoryOperations(std::string_view File)
{
	FS::path CurrentPath{ File };

	if (!FS::exists(CurrentPath))
	{
		std::cout << "Path does not exist = > " << CurrentPath.string() << std::endl;
		return;
	}


	// Create / remove directory
	CurrentPath /= "NewDir";
	if (!FS::create_directory(CurrentPath))
	{
		std::cout << "Could not create directory" << std::endl;
	}
	else
	{
		std::cout << "Directory created successfully" << std::endl;
	}

	if (!FS::remove(CurrentPath))
	{
		std::cout << "Could not delete the directory" << std::endl;
	}
	else
	{
		std::cout << "Directory removed successfully" << std::endl;
	}

	// One way to handle exceptions
	//try
	//{
	//	std::cout << FS::current_path() << std::endl;
	//	std::cout << "Changing path : " << std::endl;
	//	FS::current_path(CurrentPath);
	//	std::cout << FS::current_path() << std::endl;
	//}
	//catch (const std::exception& ex)
	//{
	//	std::cout << "Exception : " << ex.what() << std::endl;
	//}

	// Other way to handle exceptions : error handling
	std::cout << FS::current_path() << std::endl;
	std::cout << "Changing path : " << std::endl;
	std::error_code ErrorCode{};
	FS::current_path(CurrentPath, ErrorCode);

	if (ErrorCode)
	{
		std::cout << "Error : " << ErrorCode.message() << std::endl;
		return;
	}

	std::cout << FS::current_path() << std::endl;
}

void ShowPermissions(FS::perms Permissions)
{
	std::cout << ((Permissions & FS::perms::owner_read) != FS::perms::none ? "r" : "-")
		<< ((Permissions & FS::perms::owner_write) != FS::perms::none ? "w" : "-")
		<< ((Permissions & FS::perms::owner_exec) != FS::perms::none ? "x" : "-")
		<< ((Permissions & FS::perms::group_read) != FS::perms::none ? "r" : "-")
		<< ((Permissions & FS::perms::group_write) != FS::perms::none ? "w" : "-")
		<< ((Permissions & FS::perms::group_exec) != FS::perms::none ? "x" : "-")
		<< ((Permissions & FS::perms::others_read) != FS::perms::none ? "r" : "-")
		<< ((Permissions & FS::perms::others_write) != FS::perms::none ? "w" : "-")
		<< ((Permissions & FS::perms::others_exec) != FS::perms::none ? "x" : "-")
		<< '\n';
}

void Permissions(std::string_view File)
{
	FS::path FileToModify{ File };

	if (!FS::exists(FileToModify))
	{
		std::cout << "Path does not exist = > " << FileToModify.string() << std::endl;
		return;
	}

	auto Permissions = FS::status(FileToModify).permissions();
	ShowPermissions(Permissions);
	std::cout << "Changing permissions" << std::endl;
	FS::permissions(FileToModify, FS::perms::owner_write, FS::perm_options::add);
	Permissions = FS::status(FileToModify).permissions();
	ShowPermissions(Permissions);
}

void FilesystemMain()
{
	//UsingPath();

	//DirectoryOperations(R"(D:\Courses\CompleteModernCpp\18_StandardLibraryComponentsCpp17)");

	//ListDirectory(R"(D:\Courses\CompleteModernCpp\18_StandardLibraryComponentsCpp17)");

	Permissions(R"(D:\Courses\CompleteModernCpp\18_StandardLibraryComponentsCpp17\Test.docx)");
}
