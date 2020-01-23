defmodule foo do
    def myThread(pid) do
        for 0..1000000 do
            send pid, {:open, self()}
        end
        send pid, {:closed, self()}
    end
    
    def mainThread() do
        inc_pid = spawn(__module__, :myThread,  self())
        dec_pid = spawn(__module__, :myThread,  self())
    end

end


    


