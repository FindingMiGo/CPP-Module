#include "StringConvert.hpp"

StringConvert::StringConvert() {
  input_ = "";
  size_ = 0;
  impossible_C_ = false;
  impossible_I_ = false;
  impossible_F_ = false;
  impossible_D_ = false;
  castStr();
}

StringConvert::StringConvert(std::string &str) {
  input_ = str;
  size_ = input_.length();
  impossible_C_ = false;
  impossible_I_ = false;
  impossible_F_ = false;
  impossible_D_ = false;
  castStr();
}

StringConvert::~StringConvert() {}

bool StringConvert::isChar() {
  if (size_ != 1) {
    return false;
  }
  if (std::isdigit(input_[0])) {
    return false;
  }
  if (!isprint(input_[0])) {
    return false;
  }
  c_ = static_cast<char>(input_[0]);
  return true;
}

bool StringConvert::isInt() {
  long l;
  char *end;
  errno = 0;

  l = strtol(input_.c_str(), &end, 10);
  if (*end) {
    return false;
  }
  if (*end || errno == ERANGE || l > std::numeric_limits<int>::max() ||
      l < std::numeric_limits<int>::min()) {
    return false;
  }
  i_ = static_cast<int>(l);
  return true;
}

bool StringConvert::isFloat() {
  errno = 0;
  char *end = NULL;
  float f = strtof(input_.c_str(), &end);
  std::string strend = end;
  if ((*end && strend != "f" && strend != "F") || errno == ERANGE) {
    return false;
  }
  f_ = f;
  return true;
}

bool StringConvert::isDouble() {
  errno = 0;
  char *end;
  double d = strtod(input_.c_str(), &end);
  std::string strend = end;
  if ((*end && strend != "f" && strend != "F")) {
    return false;
  }
  d_ = d;
  return true;
}

Type StringConvert::detectType() {
  if (isChar()) {
    return Char;
  }
  if (isInt()) {
    return Int;
  }
  if (isFloat()) {
    return Float;
  }
  if (isDouble()) {
    return Double;
  }

  return Incorrect;
}

void StringConvert::castStr() {
  t_ = detectType();
  std::stringstream ss;

  if (t_ == Char) {
    i_ = static_cast<int>(c_);
    ss << i_;
    size_ = ss.str().length();
    f_ = static_cast<float>(i_);
    d_ = static_cast<double>(i_);
  }

  if (t_ == Int) {
    ss << i_;
    size_ = ss.str().length();
    c_ = static_cast<char>(i_);
    if (i_ > std::numeric_limits<char>::max() ||
        i_ < std::numeric_limits<char>::min()) {
      impossible_C_ = true;
    }
    f_ = static_cast<float>(i_);
    d_ = static_cast<double>(i_);
  }

  if (t_ == Float) {
    c_ = static_cast<char>(f_);
    if (f_ > std::numeric_limits<char>::max() ||
        f_ < std::numeric_limits<char>::min() || isinff(f_) || isnanf(f_)) {
      impossible_C_ = true;
    }
    i_ = static_cast<int>(f_);
    if (f_ > std::numeric_limits<int>::max() ||
        f_ < std::numeric_limits<int>::min() || isinff(f_) || isnanf(f_)) {
      impossible_I_ = true;
    }
    d_ = static_cast<double>(f_);
  }

  if (t_ == Double) {
    c_ = static_cast<char>(d_);
    if (d_ > std::numeric_limits<char>::max() ||
        d_ < std::numeric_limits<char>::min() || isinff(d_) || isnanf(d_)) {
      impossible_C_ = true;
    }
    i_ = static_cast<int>(d_);
    if (d_ > std::numeric_limits<int>::max() ||
        d_ < std::numeric_limits<int>::min() || isinff(d_) || isnanf(d_)) {
      impossible_I_ = true;
    }
    f_ = static_cast<float>(d_);
  }

  if (t_ == Incorrect) {
    impossible_C_ = true;
    impossible_I_ = true;
    impossible_F_ = true;
    impossible_D_ = true;
  }
}

void StringConvert::printChar(std::ostream &os) const {
  os << "char: ";
  if (impossible_C_)
    os << "impossible" << std::endl;
  else if (!isprint(c_))
    os << "Non displayable\n";
  else
    os << "'" << c_ << "'" << std::endl;
}

void StringConvert::printInt(std::ostream &os) const {
  os << "int: ";
  if (impossible_I_)
    os << "impossible" << std::endl;
  else
    os << i_ << std::endl;
}

void StringConvert::printFloat(std::ostream &os) const {
  os << "float: ";
  if (impossible_F_ == true)
    os << "impossible" << std::endl;
  else if (floor(f_) == f_ && !isinff(f_) && !isnanf(f_))
    os << std::setprecision(size_) << f_ << ".0f" << std::endl;
  else
    os << std::setprecision(size_) << f_ << "f" << std::endl;
}

void StringConvert::printDouble(std::ostream &os) const {
  os << "double: ";
  if (impossible_D_ == true)
    os << "impossible" << std::endl;
  else if (floor(d_) == d_ && !isinff(d_) && !isnanf(d_))
    os << std::setprecision(size_) << d_ << ".0" << std::endl;
  else
    os << std::setprecision(size_) << d_ << std::endl;
}

void StringConvert::printType(std::ostream &os) const {
  switch (t_) {
  case Char:
    os << "char";
    break;
  case Int:
    os << "int";
    break;
  case Float:
    os << "Float";
    break;
  case Double:
    os << "Double";
    break;
  case Incorrect:
    os << "incorrect";
    break;
  default:
    os << "error";
    break;
  }
  os << std::endl;
}

std::ostream &operator<<(std::ostream &os, const StringConvert &c) {
  c.printChar(os);
  c.printInt(os);
  c.printFloat(os);
  c.printDouble(os);
  return os;
}
