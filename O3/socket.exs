defmodule Receiver do
    require Logger

    def start(port) do
        spawn fn ->
        case :gen_tcp.listen(port, [:binary, active: false, reuseaddr: true]) do
            {:ok, socket} ->
            Logger.info("Connected.")
            accept_connection(socket)
            {:error, reason} ->
            Logger.error("Could not listen: #{reason}")
        end
        end
    end
end