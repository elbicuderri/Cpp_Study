#include <iostream>
#include <boost/asio.hpp>
#include <boost/asio/buffer.hpp>
// #include <boost/asio/internet.hpp>


int main()
{
	// boost::asio::error_code ec;

    boost::system::error_code ec;

	// create a "context"
	boost::asio::io_context context;

	// get the address of somewhere we wish to connect to
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::make_address("93.184.216.34", ec)); // 80: http
	boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::make_address("127.0.0.1", ec)); 

	// create a socket, the context will deliver the implementation
	boost::asio::ip::tcp::socket socket(context);

	// tell socket to try and connect
	socket.connect(endpoint, ec);

	if (!ec)
	{
		std::cout << "Connected!" << std::endl;
	}
	else
	{
		std::cout << "Failed to connect to address:\n" << ec.message() << std::endl;
	}

	system("pause");


	return 0;
}