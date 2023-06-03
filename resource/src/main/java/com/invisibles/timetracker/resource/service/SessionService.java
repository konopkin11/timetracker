package com.invisibles.timetracker.resource.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.access.prepost.PostFilter;
import org.springframework.stereotype.Service;

import com.invisibles.timetracker.resource.model.Session;
import com.invisibles.timetracker.resource.model.SessionRepository;

@Service
public class SessionService {

    @Autowired
    SessionRepository sessionRepository;

    @PostFilter("filterObject.userId==authentication.principal.getClaims().get('preferred_username')")
    public List<Session> getAllSessionForUser(){
        return sessionRepository.findAll();
    }

    public Session saveSession(Session session){
        return sessionRepository.save(session);
    }
}
