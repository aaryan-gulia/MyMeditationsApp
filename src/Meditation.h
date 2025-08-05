#pragma once

#include <string>

class Meditation {
public:
  Meditation(std::string title, std::string content)
      : title(std::move(title)), content(std::move(content)) {};
  
  const std::string& getTitle() const {return title;}
  const std::string& getContent() const {return content;}

  void setTitle(std::string title){this->title = std::move(title);}
  void setContent(std::string content){this->content = std::move(content);}

private:
  std::string title;
  std::string content;
};
