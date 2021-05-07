#include<boost/filesystem.hpp>
#include<iostream>

namespace fs = boost::filesystem;

void testingFileSystem1() {
	fs::path myPath("F:\\tmp");
	bool pathExists = fs::exists(myPath);
	std::cout << pathExists << std::endl;

	fs::path newPath = myPath / "text.txt";
	pathExists = fs::exists(newPath);
	std::cout << pathExists << std::endl;
	fs::path myPathCreated = myPath / "TestFolder";
	fs::create_directories(myPathCreated);
	pathExists = fs::exists(myPathCreated);
	std::cout << pathExists << std::endl;
}

void testingFileSystem2() {
	fs::path myPath("F:\\tmp");
	fs::directory_iterator itr(myPath);
	fs::directory_iterator end_itr;

	std::cout << myPath.root_path() << std::endl;
	std::cout << myPath.parent_path() << std::endl;

	while (itr != end_itr && !fs::is_directory(itr->path())) {
		std::cout << "------------------------" << std::endl;
		std::cout << "Path: " << itr->path() << std::endl;
		std::cout << "Filename: " << itr->path().filename() << std::endl;
		std::cout << "Is File: " << fs::is_regular_file(itr->path()) << std::endl;
		std::cout << "File Size: " << fs::file_size(itr->path()) << std::endl;
		std::cout << "------------------------" << std::endl;
		itr++;
	}
}

void testingFileSystem3() {
	try {
		fs::path originalFile("F:\\tmp\\monteCarloTest.bin");
		fs::path copiedFile("F:\\tmp\\monteCarloTestCopied.bin");
		fs::path newFileName("F:\\tmp\\monteCarloTestRenamed.bin");

		fs::directory_iterator itr(copiedFile.parent_path());
		fs::directory_iterator end_itr;

		while (itr != end_itr) {
			std::cout << "Directory files begin: " << itr->path() << std::endl;
			std::cout << "---------------------------------" << std::endl;
			itr++;
		}

		if (!fs::exists(copiedFile)) {
			fs::copy_file(originalFile, copiedFile);
		}

		fs::directory_iterator itr1(copiedFile.parent_path());
		while (itr1 != end_itr) {
			std::cout << "Directory files after copy: " << itr1->path() << std::endl;
			std::cout << "--------------------------------" << std::endl;
			itr1++;
		}

		fs::rename(copiedFile, newFileName);

		fs::directory_iterator itr2(copiedFile.parent_path());
		while(itr2!=end_itr){
			std::cout << "Directory files after rename: " << itr2->path() << std::endl;
			std::cout << "--------------------------------" << std::endl;
			itr2++;
		}

		fs::remove(newFileName);
		fs::directory_iterator itr3(copiedFile.parent_path());
		while (itr3 != end_itr) {
			std::cout << "Directory files after remove: " << itr3->path() << std::endl;
			std::cout << "--------------------------------" << std::endl;
			itr3++;
		}
	}
	catch (fs::filesystem_error const& fe) {
		std::cout << fe.what() << std::endl;
	}
}

//int main() {
//	//testingFileSystem1();
//	//testingFileSystem2();
//	testingFileSystem3();
//}