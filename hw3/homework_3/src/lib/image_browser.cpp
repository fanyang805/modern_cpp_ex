#include "image_browser.hpp"
#include "html_writer.hpp"
#include <iostream>

namespace image_browser {

void AddFullRow(const ImageRow &row, bool first_row) {
  std::cout << "<div class=\"row\">\n";

  for (const ScoredImage &image : row) {
    // auto [img_path, score] = image;
    if (first_row) {
      html_writer::AddImage(std::get<0>(image), std::get<1>(image), first_row);
      first_row = false;
    } else {
      html_writer::AddImage(std::get<0>(image), std::get<1>(image));
    }
  }
  std::cout << "</div>\n";
}

void CreateImageBrowser(const std::string &title, const std::string &stylesheet,
                        const std::vector<ImageRow> &rows) {
  std::cout << "<!DOCTYPE html>\n"
            << "<html>\n";
  html_writer::AddTitle(title);
  html_writer::AddCSSStyle(stylesheet);
  html_writer::OpenBody();

  bool first_row = true;
  for (const ImageRow &row : rows) {
    if (first_row) {
      AddFullRow(row, first_row);
      first_row = false;
    } else {
      AddFullRow(row);
    }
  }

  html_writer::CloseBody();

  std::cout << "</html>\n";
}

} // namespace image_browser