template<typename... Str>
class lazy_str_concat_helper;

template<typename LastString, typename... Str>
class lazy_str_concat_helper<LastString, Str...>
{
    public:
        lazy_str_concat_helper(const LastString& str, const lazy_str_concat_helper<Str...>& helper):last_string_{str},prev_strings_{helper}  {}

        lazy_str_concat_helper<std::string, LastString, Str...> operator+(const std::string& str) const
        {
            return lazy_str_concat_helper<std::string, LastString, Str...>{str, *this};
        }
        
        std::size_t size() const
        {
            return last_string_.size() + prev_strings_.size();
        }

        //conversion function
        operator std::string() const
        {
            std::string result(size(), '\0');
            eval(result.end());
            return result;
        }

        template<typename Iter>
        void eval(Iter end) const
        {
            const auto begin = end-last_string_.size();
            std::copy(last_string_.cbegin(), last_string_.cend(), begin);
            prev_strings_.eval(begin);
        }

    private:

        LastString last_string_;
        lazy_str_concat_helper<Str...> prev_strings_;
};

template<>
class lazy_str_concat_helper<>
{
    public:
        std::size_t size() const
        {
            return 0;
        }
        
        template<typename Iter>
        void eval(Iter) const
        {
        }

        lazy_str_concat_helper<std::string> operator+(const std::string& str) const
        {
            return lazy_str_concat_helper<std::string>{str, *this};
        }

};
