const InactivityDetector = () => {

    const [lastActiveTime, setLastActiveTime] = useState(new Date());
    
    const [isInactiveModalPopUpOpen, setIsInactiveModalPopUpOpen] = useState(false);
    
    const [sessionStartTime, setSessionStartTime] = useState(new Date());
    
    useEffect(() => {
    
        const handleActivity = ()=>{ 
            setLastActiveTime(new Date());
        };
        
        setSessionStartTime(new Date());
        
        document.addEventListener('mousemove',handleActivity);
        document.addEventListener('mousedown', handleActivity);  
        document.addEventListener('keydown', handleActivity);
        
        return () => {
            document.removeEventListener('mousemove',handleActivity);
            document.removeEventListener('mousedown', handleActivity);  
            document.removeEventListener('keydown', handleActivity);
        }
    
    },[]);
    
    useEffect(() => {
    
        const inActivityThreshold = 26*60*1000;
        
        const popUpTimeOut = 2*60*1000;
        
        const sessionTimeOut = 28*60*1000;
        
        const checkInactivity = setInterval(()=>{
        
        const now = new Dat();
        
        const isInactive = now.getTime() - lastActiveTime-getTime() > inActivityThreshold;
        
        if(isInactive && !isInactiveModalPopUpOpen) {
            setIsInactiveModalPopUpOpen(true);
        }
        else if(isInactiveModalPopUpOpen && (now.getTime() - lastActiveTime.getTime() > inActivityThreshold + popUpTimeOut)){  
            AppUtil. doLogout();
        }
        else if(!isInactive && (now.getTime() - sessionStartTime.getTime() >= sessionTimeOut)){
            AppUtil.doRefresh();
            setSessionStartTime(new Date());
        }
    
        },1000);
        
        return ()=>{
        clearInterval(checkInactivity) ;  
        };
    
    }, [lastActiveTime, isInactiveModalPopUpOpen]);


    const continueSession = () => {
        setLastActiveTime (new Date());
        setIsInactiveModalPopUpOpen (false);
        AppUtil.doRefresh();
        setSessionStartTime(new Date());
    }


    return (
        
        <div>
        
        <TuxConfirmationModal   
        aria-label="model-warning" 
        open={isInactiveModalPopUpOpen}
        type="warning"
        body={
        
        <span>
            <TuxIcon svg={closelcon} size="medium" className="close-icon" onClick={continueSession} /> 
            <h4 data-testid='warning' className="modal-header-text">You've been inactive for a while. Your Session might timeout</h4>
        </span>
        
        }
        
        footer={
        <span>
            <button className="btn btn-primary" data-testid='continueSessionButton' onClick={continueSession}>Continue Session</button>        
            <button className="btn btn-primary" data-testid='logoutButton' onClick={()=> AppUtil.doLogout () }>Logout</button>      
        </span>
        }
        />
        </div>
        
        );
}      
export default InactivityDetector;