package com.invisibles.timetracker.resource.controller;

import java.security.Principal;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.HttpStatusCode;
import org.springframework.http.ResponseEntity;
import org.springframework.security.access.prepost.PostFilter;
import org.springframework.security.access.prepost.PreAuthorize;
import org.springframework.security.access.prepost.PreFilter;
import org.springframework.security.core.annotation.AuthenticationPrincipal;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.invisibles.timetracker.resource.model.Session;
import com.invisibles.timetracker.resource.model.SessionRepository;
import com.invisibles.timetracker.resource.service.SessionService;

@RestController
public class SessionController {

    @Autowired
    private SessionService sessionService;

    @PostMapping(value = "/session")
    @PreAuthorize("#session.userId == authentication.principal.getClaims().get('preferred_username')")
    public ResponseEntity<Session> createSession(@RequestBody Session session/*, @AuthenticationPrincipal Principal principal*/) {
        System.out.println(session.getUserId());
        return new ResponseEntity<>(sessionService.saveSession(session), HttpStatus.OK);
    }

    @GetMapping(value = "/session")
    public ResponseEntity<List<Session>> getSession() {
        return new ResponseEntity<>(sessionService.getAllSessionForUser(), HttpStatus.OK);
    }

}
