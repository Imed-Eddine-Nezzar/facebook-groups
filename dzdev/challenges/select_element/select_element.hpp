#ifndef __SELECT_ELEMENT_HPP__
#define __SELECT_ELEMENT_HPP__

namespace local {

template <
  class InputIt,
  typename BinaryPred
>
InputIt select_element(InputIt first, InputIt last, BinaryPred bin_pred) {
  InputIt element{first};
  while (++first != last) {
    if (bin_pred(*first, *element))
      element = first;
  }
  return element;
}

} // namespace local

#endif // __SELECT_ELEMENT_HPP__