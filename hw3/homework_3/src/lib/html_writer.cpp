// #include <fstream>
#include "html_writer.hpp"
#include <iomanip>
#include <iostream>
#include <string>

namespace html_writer {

// void OpenDocument() {
//   std::ifstream readhtml{"out_app.html"};
//   if (!readhtml) {
//     std::cerr << "Canot open the html file!\n";
//   }
//   while (readhtml) {
//     std::string readline;
//     std::getline(readhtml, readline);
//     std::cout << readline << std::endl;
//   }
// }
// void OpenDocument() { std::cout << "<!DOCTYPE html>\n<html>"; }

// void CloseDocument() { std::cout << "</html>\n"; }

void AddCSSStyle(const std::string &stylesheet) {
  std::cout << "<head>\n"
            << "<link rel=\"stylesheet\" type=\"text/css\" href=\""
            << stylesheet << "\"/>\n"
            << "</head>\n";
}

void AddTitle(const std::string &title) {
  std::cout << "<title>" << title << "</title>\n";
}

void OpenBody() { std::cout << "<body>\n"; }

void CloseBody() { std::cout << "</body>\n"; }

void OpenRow() { std::cout << "<div class=\" row \">\n"; }

void CloseRow() { std::cout << " </div>\n"; }

void AddImage(const std::string &img_path, float score, bool highlight) {
  std::string img_extension = img_path.substr(img_path.find_last_of(".") + 1);
  if (img_extension != "png" && img_extension != "jpg") {
    std::cerr << "Image file format error. Please use .png or .jpg.\n";
  }

  if (highlight) {
    std::cout
        << "<div class=\"column\" style = \"border: 5px solid green;\">\n";
  } else {
    std::cout << "<div class = \"column\">\n";
  }
  std::cout << "<h2>" << img_path.substr(img_path.find_last_of("/") + 1)
            << "</h2>\n";
  std::cout << "<img src=\"" << img_path << "\" />\n";
  std::cout << "<p>score = ";
  std::cout << std::setprecision(2) << std::fixed << score << "</p>\n";
  std::cout << "</div>\n";
}
} // namespace html_writer