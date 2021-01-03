#include <iostream>
#include <boost/asio.hpp>
#include <asio/buffer.hpp>
#include <asio/internet.hpp>


int main()
{
	asio::error_code ec;

	// create a "context"
	asio::io_context context;

	// get the address of somewhere we wish to connect to
	asio::ip::tcp::endpoint endpoint(asio::ip::multiple_exceptions::make_address("93.184.216.34", ec), 80); // 80: http
	asio::ip::tcp::endpoint endpoint(asio::ip::multiple_exceptions::make_address("127.0.0.1", ec), 80); 

	// create a socket, the context will deliver the implementation
	asio::ip::tcp::socket socket(context);

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