#include <iostream>
#include <boost/asio.hpp>
// using boost::asio::ip::tcp;

int main(int argc, char** argv)
{
    if (argc != 3)
        {
            std::cout << "Wrong parameter\n";
            std::cout << "Example usage 127.0.0.1 1234" << std::endl;
        }

    auto const address = boost::asio::ip::make_address(argv[1]);
    auto const port = std::atoi(argv[2]);

    boost::asio::io_service io_service;

    boost::system::error_code ec;

    boost::asio::ip::tcp::acceptor acceptor_(
        io_service,
        boost::asio::ip::tcp::endpoint(address, port)
    );
    boost::asio::ip::tcp::socket socket_(io_service);

    acceptor_.accept(socket_);
    boost::asio::read_until(socket_, buf, "\", ec);
    if (ec) { std::cout << ec.message() << std::endl; return -1; }
    std::

    return 0;
}